#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

long long n, m, h;
long long arr[101][101][101];
long long dist[101][101][101];
long long dx[6] = { -1,1,0,0,0,0 };
long long dy[6] = { 0,0,-1,1,0,0 };
long long dz[6] = { 0,0,0,0,-1,1 };
queue<pair<pair<long long, long long>,long long>>q;
void bfs() {
	while (!q.empty()) {
		long long curX = q.front().first.first;
		long long curY = q.front().first.second;
		long long curZ = q.front().second;
		if (dist[curX][curY][curZ] == -1) dist[curX][curY][curZ] = 0;
		q.pop();
		for (long long i = 0; i < 6; i++) {
			long long nx = curX + dx[i];
			long long ny = curY + dy[i];
			long long nz = curZ + dz[i];
			if (nx<1 || ny<1 || nz<1|| nx>m || ny>n||nz>h) continue;
			if (arr[nx][ny][nz] != 0 || dist[nx][ny][nz] > -1) continue;
			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			q.push({ { nx,ny } ,nz });

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(dist, -1, sizeof(dist));
	long long ans = -1;
	cin >> n >> m >> h;
	for (long long i = 1; i <= h; i++) {
		for (long long j = 1; j <= m; j++)
		{
			for (long long k = 1; k <= n; k++) {
				{
					cin >> arr[j][k][i];
					if (arr[j][k][i] == 1) q.push({ { j,k } ,i });
				}
			}
		}

	}
	bfs();
	bool flag = false;
	for (long long i = 1; i <= h; i++) {
		for (long long j = 1; j <= m; j++) {
			for (long long k = 1; k <= n; k++) {
				if (dist[j][k][i] == -1 && arr[j][k][i] != -1) {
					flag = true;
				}
				else if (dist[j][k][i] > -1 && arr[j][k][i] != -1) {
					ans = max(ans, dist[j][k][i]);
				}
			}
		}
	}


	if (flag) cout << "-1\n";
	else cout << ans;
}
