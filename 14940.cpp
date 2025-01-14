#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
pair<int, int>start;
int arr[1001][1001], visited[1001][1001];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
void bfs(int a, int b) {
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
			if (nx > n || nx<1 || ny>m || ny < 1) continue;
			if (arr[nx][ny] == 0 || visited[nx][ny] > -1) continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}
int main() {
	cin >> n >> m;
	memset(visited, -1, sizeof(visited));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				start = (make_pair(i, j));
		}
	bfs(start.first, start.second);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			if (visited[i][j] == -1 && arr[i][j]==0) visited[i][j] = 0;
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}
