#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, maxi;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int arr[301][301], pre[301][301];
bool visited[301][301];

void melt() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (pre[i][j] > 0) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k]; // 수정된 부분
					if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
					if (pre[nx][ny] == 0) cnt++;
				}
				arr[i][j] = max(0, pre[i][j] - cnt);
			}
		}
	}
}


void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (arr[nx][ny] == 0 || visited[nx][ny])continue;
			q.push({ nx,ny });
			visited[nx][ny] = true;

		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			maxi = max(maxi, arr[i][j]);
		}

	int k = 0;
	while(1) {
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				pre[i][j] = arr[i][j];

		if (k > 0) melt();
		bool flag = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] > 0) {
					flag = true;
					break;
				}
			}
		}
		if (!flag) break;
		int tmp = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (arr[i][j] > 0 && !visited[i][j]) {
					tmp++;
					bfs(i, j);
				}
			}
		if (tmp > 1) {
			cout << k;
			return 0;
		}
		k++;
	}
	cout << 0;
}
