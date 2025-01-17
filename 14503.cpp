#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n, m, r, c, direct, ans;
int arr[50][50], visited[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
void bfs() {
	visited[r][c] = 1;
	ans++;
	int curX = r, curY = c;
	while (1) {
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == 1 || visited[nx][ny] == 1) {
				continue;
			}
			flag = true;
		}
		if (flag) {
			direct = (direct + 3) % 4;
			int nx = curX + dx[direct];
			int ny = curY + dy[direct];
			if (arr[nx][ny]==0&&visited[nx][ny]==0) {
				visited[nx][ny] = 1;
				//cout << nx << " " << ny << " " << "\n";
				curX = nx;
				curY = ny;
				ans++;
			}
		}
		else {
			int nx = curX + dx[(direct + 2) % 4];
			int ny = curY + dy[(direct + 2) % 4];
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) return;
			if (arr[nx][ny] == 1) return;
			if (visited[nx][ny]==0) {
				//cout << nx << " " << ny << "\n";
				visited[nx][ny] = 1;
				ans++;
			}
			curX = nx;
			curY = ny;
		}
	}
}
int main() {
	cin >> n >> m;
	cin >> r >> c >> direct;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	

	bfs();
	cout << ans;
}
