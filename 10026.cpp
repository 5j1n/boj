#include <iostream>
#include <queue>

using namespace std;

char arr[101][101];
bool visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n;

void bfs(int x, int y, char color) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx<1 || ny<1 || nx>n || ny>n) continue;
			if (arr[nx][ny] != color || visited[nx][ny] == true) continue;
			q.push({ nx,ny });
			visited[nx][ny] = true;
		}
	}
}
int main() {

	int nor_cnt = 0, abnor_cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == false) {
				nor_cnt++;
				bfs(i, j, arr[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[i][j] = false;
			if (arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == false) {
				abnor_cnt++;
				bfs(i, j, arr[i][j]);
			}
		}
	}

	cout << nor_cnt << " " << abnor_cnt;

}
