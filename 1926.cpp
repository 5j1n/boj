#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[501][501];
bool visited[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs(int x, int y) {
	int ans = 0;
	visited[x][y] = true;
	queue<pair<int, int>>q;
	q.push({ x,y });
	ans++;
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (arr[nx][ny] == 0 || visited[nx][ny] == true) continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
			ans++;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cnt = 0, maxi = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				cnt++;
				maxi = max(bfs(i, j), maxi);
			}
		}
	}

	cout << cnt << "\n" << maxi;

}
