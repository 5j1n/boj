#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int visited[51][51], arr[51][51];
int dx[] = { -1,1,0,0,-1,1,-1,1 }, dy[] = { 0,0,-1,1,1,1,-1,-1 };

void dfs(int a, int b) {
	visited[a][b] = 1;
	queue<pair<int, int>>q;
	q.push({ a,b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>m) continue;
			if (arr[nx][ny] == 0 || visited[nx][ny] == 1) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}
int main() {
	while (1) {

		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		int ans = 0;

		cin >> m >> n;
		if (!n && !m) return 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> arr[i][j];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (arr[i][j] == 1 && visited[i][j] == 0)
				{
					dfs(i, j);
					ans++;
				}

		cout << ans << "\n";
	}
}
