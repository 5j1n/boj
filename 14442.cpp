#include <iostream>
#include <queue>

using namespace std;

char arr[1001][1001];
int visited[1001][1001][11];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m, k;

bool bfs() {
	queue<pair<pair<int, int>, pair<int, int>>>q;
	q.push({ {1,1},{0,0} });
	visited[1][1][0] = 1;
	while (!q.empty()) {
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int cnt = q.front().second.first;
		int use = q.front().second.second;
		q.pop();
		if (curX == n && curY == m) {
			cout << cnt + 1;
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (arr[nx][ny] == '1' && use < k && visited[nx][ny][use + 1] == 0) {
				visited[nx][ny][use + 1] = visited[curX][curY][use] + 1;
				q.push({ {nx,ny},{cnt + 1,use + 1} });
			}

			else if (arr[nx][ny] == '0' && visited[nx][ny][use] == 0) {
				visited[nx][ny][use] = visited[curX][curY][use] + 1;
				q.push({ {nx,ny},{cnt + 1,use} });
			}
		}
	}
	return false;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	bool flag = bfs();

	if (!flag) cout << -1;
}
