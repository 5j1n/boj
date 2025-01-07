#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int dx[8] = { -2,-1,1,2,-2,-1,1,2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
int n, start_x, start_y, end_x, end_y;
int visited[301][301];

void bfs(int x, int y) {
	visited[x][y] = 0;
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty()) {
		if (visited[end_x][end_y] > 0) break;
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx < 0 || ny<0 || nx>n-1 || ny > n-1) continue;
			if (visited[nx][ny] > -1) continue;
			visited[nx][ny] = visited[curX][curY] + 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(visited, -1, sizeof(visited));
		cin >> n;
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;

		bfs(start_x, start_y);
		cout << visited[end_x][end_y]<<"\n";
	}
}
