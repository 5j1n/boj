#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int k, m, n;
int arr[201][201];
int visited[201][201][31];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int hdx[8] = { -2,-1,1,2,-2,-1,1,2 };
int hdy[8] = { 1,2,2,1,-1,-2,-2,-1 };

bool bfs() {
	visited[1][1][0] = 0;
	
	queue<pair<pair<int, int>, pair<int, int>>>q;
	q.push({ {1,1},{0,0}});
	while (!q.empty()) {
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int cnt = q.front().second.first;
		int use = q.front().second.second;
		q.pop();
		if (curX == n && curY == m) {
			cout << cnt;
			return true;
		}
		if (use < k) {
			for (int i = 0; i < 8; i++) {
				int nx = curX + hdx[i];
				int ny = curY + hdy[i];
				if (nx<1 || ny<1 || nx>n || ny>m) continue;
				if (arr[nx][ny] == 1 || visited[nx][ny][use + 1]>-1)continue;
				visited[nx][ny][use + 1] = visited[curX][curY][use] + 1;
				q.push({ {nx,ny},{cnt + 1,use + 1} });
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (arr[nx][ny] == 1 || visited[nx][ny][use]>-1)continue;
			visited[nx][ny][use] = visited[curX][curY][use] + 1;
			q.push({ {nx,ny},{cnt + 1,use} });
		}
	}
	return false;
}

int main() {
	cin >> k >> m >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	memset(visited, -1, sizeof(visited));

	bool flag = bfs();
	if (!flag) cout << -1;
}
