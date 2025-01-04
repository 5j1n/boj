#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, maxi = 0, ans = 1;
int arr[101][101], visited[101][101];
int dx[4] = { -1,1,0,0 }, dy[4]{ 0,0,-1,1 };

void bfs(int a, int b, int k) {
	visited[a][b] = 1;
	queue<pair<int, int>>q;
	q.push({ a,b });
	while (!q.empty()) {
		int cur1 = q.front().first;
		int cur2 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nxt1 = cur1 + dx[i];
			int nxt2 = cur2 + dy[i];
			if (nxt1 > 0 && nxt1 <= n && nxt2 > 0 && nxt2 <= n) {
				if (visited[nxt1][nxt2] == 0 && arr[nxt1][nxt2] - k > 0) {
					visited[nxt1][nxt2] = 1;
					q.push({ nxt1,nxt2 });
				}
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			maxi = max(maxi, arr[i][j]);
		}

	for (int k = 1; k < maxi; k++) {
		memset(visited, 0, sizeof(visited));
		int tmp = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] - k > 0 && visited[i][j]==0)
				{
					tmp++;
					bfs(i, j, k);
				}
			}
		ans = max(ans, tmp);
	}
	cout << ans;
}
