#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int visited[101][101], arr[101][101];
int n, m, k, ans;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

int bfs(int a, int b) {
	int tmp = 1;
	visited[a][b] = 1;
	queue<pair<int, int>>q;
	q.push({ a,b });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (nx > n || nx<1 || ny>m || ny < 1) continue;
			if (!arr[nx][ny] || visited[nx][ny]) continue;
			tmp++;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}

	return tmp;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				ans = max(ans,bfs(i, j));
			}
		}
	}
	
	cout << ans;
}
