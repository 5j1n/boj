#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

long long n, m;
long long arr[1001][1001];
long long dist[1001][1001];
long long dx[4] = { -1,1,0,0 };
long long dy[4] = { 0,0,-1,1 };
queue<pair<int, int>>q;
void bfs() {
	while (!q.empty()) {
		long long curX = q.front().first;
		long long curY = q.front().second;
		if (dist[curX][curY] == -1) dist[curX][curY] = 0;
		q.pop();
		for (long long i = 0; i < 4; i++) {
			long long nx = curX + dx[i];
			long long ny = curY + dy[i];
			if (nx<1 || ny<1 || nx>m || ny>n) continue;
			if (arr[nx][ny] != 0 || dist[nx][ny]>-1) continue;
			dist[nx][ny] = dist[curX][curY] + 1;
			q.push({ nx,ny });
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(dist, -1, sizeof(dist));
	long long ans = -1;
	cin >> n >> m;
	for (long long i = 1; i <= m; i++) {
		for (long long j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push({ i,j });
		}

	}
	bfs();
	bool flag = false;
	for (long long i = 1; i <= m; i++) {
		for (long long j = 1; j <= n; j++) {
			if (dist[i][j] == -1 && arr[i][j]!=-1) {
				flag = true;
			}
			else if (dist[i][j] > -1 && arr[i][j] != -1) {
				ans = max(ans, dist[i][j]);
			}
		}
	}


	if (flag) cout << "-1\n";
	else cout << ans;
}
