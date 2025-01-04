#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int n, m;
int arr[101][101];
int visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int x, int y) {
	visited[x][y] = 0;
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (arr[nx][ny] == 0 || visited[nx][ny] > -1) continue;
			visited[nx][ny] = visited[curX][curY] + 1;
			q.push({ nx,ny });
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(visited, -1, sizeof(visited));

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= m; j++)
			arr[i][j] = tmp[j - 1] -'0';
	}
	bfs(1, 1);

	cout << visited[n][m] + 1;
}
