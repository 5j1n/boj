#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int arr[110][110];
bool visited[110][110], already[110][110];
int cnt, width, break_width;
int n, m;
vector<pair<int, int>>wall;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs(int x, int y) {
	int ret = 0;
	visited[x][y] = true;
	queue < pair<int, int>>q;
	q.push({ x,y });
	if (x % 2 == 0 && y % 2 == 0) ret++;
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx < 1 || ny < 1 || nx >= 2 * n + 1 || ny >= 2 * m + 1) continue;
			if (visited[nx][ny])continue;
			if (!arr[nx][ny]) continue;
			q.push({ nx,ny });
			visited[nx][ny] = true;
			if (nx%2==0&&ny%2==0)ret++;
			//ret++;
		}
	}
	return ret;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i <= 2 * n  + 1; i++) {
		for (int j = 0; j <= 2 * m + 1; j++) {
			if ((i % 2) && (j % 2)) {
				arr[i][j] = 0;
			}
			else arr[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int tmp;
			cin >> tmp;

			bool one = false, two = false, four = false, eight = false;
			if (tmp >= 8) {
				eight = true;
				tmp -= 8;
			}
			if (tmp >= 4) {
				four = true;
				tmp -= 4;
			}
			if (tmp >= 2) {
				two = true;
				tmp -= 2;
			}
			if (tmp >= 1) {
				one = true;
				tmp -= 1;
			}
			if (one) {
				arr[2 * i][2 * j - 1] = 0;
				if (!already[2 * i][2 * i - 1]) {
					wall.push_back({ 2 * i,2 * j - 1 });
					already[2 * i][2 * j - 1] = true;
				}
				//cout << 2 * i << ", " << 2 * j - 1 << "\n";
			}
			if (two) {
				arr[2 * i - 1][2 * j] = 0;
				if (!already[2 * i-1][2 * j]) {
					wall.push_back({ 2 * i - 1,2 * j });
					already[2 * i-1][2 * j] = true;
				}
				//cout << 2 * i -1 << ", " << 2 * j << "\n";
			}
			if (four) {
				arr[2 * i][2 * j + 1] = 0;
				if (!already[2 * i][2 * j + 1]) {
					wall.push_back({ 2 * i,2 * j+1 });
					already[2 * i][2 * j+1] = true;
				}
				//cout << 2 * i << ", " << 2 * j + 1 << "\n";
			}
			
			if (eight) {
				arr[2 * i + 1][2 * j] = 0;
				if (!already[2 * i + 1][2 * j]) {
					wall.push_back({ 2 * i + 1,2 * j });
					already[2 * i + 1][2 * j] = true;
				}
				//cout << 2 * i + 1 << ", " << 2 * j << "\n";
			}
			//cout << "--\n";
		}
	}


	for (int i = 1; i <= 2 * n + 1; i++) {
		for (int j = 1; j <= 2 * m + 1; j++) {
			if (!visited[i][j] && arr[i][j]) {
				if ((i % 2) && (j % 2))continue;
				int ret = bfs(i, j);
				cnt++;
				width = max(ret, width);
			}
		}
	}
	cout << cnt << "\n" << width << "\n";
	
	for (int k = 0; k < wall.size(); k++) {
		arr[wall[k].first][wall[k].second] = 1;
		memset(visited, false, sizeof(visited));
		int ret = bfs(wall[k].first, wall[k].second);
		break_width = max(break_width, ret);	
		arr[wall[k].first][wall[k].second] = 0;
	}
	cout << break_width;
}
