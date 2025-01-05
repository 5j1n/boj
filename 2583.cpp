#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
int start_x, start_y, end_x, end_y;
using namespace std;

int arr[101][101], visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int m, n, k;
int bfs(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx >= m || ny >= n || nx < 0 || ny < 0) continue;
			if (arr[nx][ny] == 1 || visited[nx][ny] == 1) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
			cnt++;
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<int>v;
	int ans = 0;
	cin >> m >> n >> k;
	while (k--) {
		cin >> start_x >> start_y >> end_x >> end_y;
		for (int i = start_y; i < end_y; i++)
			for (int j = start_x; j < end_x; j++)
				arr[i][j] = 1;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 && visited[i][j] == 0) {
				ans++;
				v.push_back(bfs(i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	cout << ans << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}
