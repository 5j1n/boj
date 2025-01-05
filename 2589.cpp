#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

char arr[51][51];
int visited[51][51], ans, n, m;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int bfs(int a, int b) {
	int tmp = 0;
	memset(visited, -1, sizeof(visited));
	visited[a][b] = 0;
	queue<pair<int, int>>q;
	q.push({ a,b });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx<1 || nx>n || ny<1 || ny>m) continue;
			if (arr[nx][ny] == 'W' || visited[nx][ny] > -1) continue;
			visited[nx][ny] = visited[x][y] + 1;
			tmp = max(tmp, visited[nx][ny]);
			q.push({ nx,ny });
		}
	}

	return tmp;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (arr[i][j] == 'L')
				ans = max(ans,bfs(i, j));

	cout << ans;
}
