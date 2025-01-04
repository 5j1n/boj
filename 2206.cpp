#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

char arr[1001][1001];
int visited[1001][1001][2];
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs() {
	visited[1][1][0] = 1;
	int flag = 0;
	queue<pair<pair<int,int>,int>> q;
	q.push({ { 1,1 }, 0 });
	while (!q.empty()) {
		int curx = q.front().first.first;
		int cury = q.front().first.second;
		flag = q.front().second;
		q.pop();
		if (curx == n && cury == m) {
			cout << visited[n][m][flag];
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (arr[nx][ny] == '1' && flag == 0 && visited[nx][ny][0] == 0 && visited[nx][ny][1]==0) {
				visited[nx][ny][1] = visited[curx][cury][0] + 1;
				q.push({ {nx,ny},1 });
			}
			else if (arr[nx][ny] == '0' && flag == 1 && visited[nx][ny][1] == 0) {
				visited[nx][ny][1] = visited[curx][cury][1] + 1;
				q.push({ {nx,ny},1 });
			}
			else if (arr[nx][ny] == '0' && flag == 0 && visited[nx][ny][0] == 0) {
				visited[nx][ny][0] = visited[curx][cury][0] + 1;
				q.push({ {nx,ny},0 });
			}
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	if (bfs() == 1) cout << "-1\n";
	
}
