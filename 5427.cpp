#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
char arr[1001][1001];
int f_visited[1001][1001], s_visited[1001][1001];

pair<int, int>s_loc;
queue<pair<int, int>>q;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs1() {

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		if (f_visited[curX][curY] == 987654321) {
			f_visited[curX][curY] = 0;
			//cout << curX << " " << curY << f_visited[curX][curY] << "\n";
		}
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx > n || ny > m || nx < 1 || ny < 1) continue;
			if (arr[nx][ny] == '#' || f_visited[nx][ny]<987654321) continue;
			f_visited[nx][ny] = f_visited[curX][curY] + 1;
			//cout << nx << " " << ny << " "<<f_visited[nx][ny]<<"\n";
			q.push({ nx,ny });
		}
	}
}
void bfs2() {
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		if (s_visited[curX][curY] == 987654321) {
			s_visited[curX][curY] = 0;
			//cout << curX << " " << curY << f_visited[curX][curY] << "\n";
		}
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx > n || ny > m || nx < 1 || ny < 1) continue;
			if (arr[nx][ny] == '#' || arr[nx][ny]=='*' || s_visited[nx][ny] < 987654321) continue;
			s_visited[nx][ny] = s_visited[curX][curY] + 1;
			q.push({ nx,ny });
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n;
		int ans = 987654321;
		for (int i = 1; i <= 1000; i++) {
			for (int j = 1; j <= 1000; j++) {
				f_visited[i][j] = 987654321;
				s_visited[i][j] = 987654321;
				arr[i][j] = '#';
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '*') q.push({ i,j });
				else if (arr[i][j] == '@') s_loc = { i,j };
			}
		}

		bfs1();
		q.push(s_loc);
		bfs2();

		bool flag = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1 || i == n || j == 1 || j == m) {
					if (f_visited[i][j] > s_visited[i][j]) {
						flag = true;
						ans = min(ans, s_visited[i][j] + 1);
					}
				}
			}
		}

		if (!flag) cout << "IMPOSSIBLE\n";
		else cout << ans << "\n";

	}
}
