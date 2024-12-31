#include <iostream>
#include <queue>
using namespace std;

int arr[51][51], visited[51][51];
int m, n, k;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
void bfs(int a, int b) {
	visited[a][b] = 1;
	queue < pair<int, int>>q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nxtX = curX + dx[i];
			int nxtY = curY + dy[i];
			if (nxtX < 0 || nxtX >= n || nxtY < 0 || nxtY >= m) continue;
			if (arr[nxtX][nxtY] == 0 || visited[nxtX][nxtY] == 1) continue;
			q.push({ nxtX,nxtY });
			visited[nxtX][nxtY] = 1;
		}
	}

}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int cnt = 0;
		for (int i = 0; i<=50; i++)
			for (int j = 0; j <= 50; j++)
			{
				arr[i][j] = 0;
				visited[i][j] = 0;
			}
		
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int y, x;
			cin >> y >> x;
			arr[x][y] = 1;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1 && visited[i][j] == 0) {
					cnt++;
					bfs(i, j);
				}
			}
		cout << cnt<<"\n";
	}
}
