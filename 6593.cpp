#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n, m, l, end_x, end_y, end_z;
char arr[31][31][31];
int visited[31][31][31];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
queue<pair<pair<int, int>, int>>q;

void bfs() {
	int x = q.front().first.first;
	int y = q.front().first.second;
	int z = q.front().second;
	visited[x][y][z] = 0;
	while (!q.empty()) {
		int curx = q.front().first.first;
		int cury = q.front().first.second;
		int curz = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			int nz = curz + dz[i];

			if (nx<1 || ny<1 || nz<1 || nx>n || ny>m || nz>l) continue;
			if (arr[nx][ny][nz] == '#' || visited[nx][ny][nz] != -1) continue;
			visited[nx][ny][nz] = visited[curx][cury][curz] + 1;
			q.push({ {nx,ny} ,nz });
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (1) {
		cin >> l >> n >> m;
		if (l == 0 && n == 0 && m == 0) break;
		for (int i = 1; i<=30; i++)
			for (int j = 1; j<=30; j++)
				for (int k = 1; k <= 30; k++){
					arr[i][j][k] = '#';
					visited[i][j][k] = -1;
				}
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= m; k++) {
					char tmp;
					cin >> tmp;
					if (tmp == '\n') {
						k--;
						continue;
					}
					if (tmp == 'S')
						q.push({ { j,k }, i });
					else if (tmp == 'E') {
						end_x = j;
						end_y = k;
						end_z = i;
					}
					arr[j][k][i] = tmp;
				}
			}
		}
		bfs();

		if (visited[end_x][end_y][end_z] == -1)
			cout << "Trapped!\n";
		else 
			cout <<"Escaped in "<< visited[end_x][end_y][end_z] << " minute(s).\n";
		
	}
	
}
