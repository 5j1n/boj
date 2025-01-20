#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int arr[51][51];
bool visited[51][51];
int n, l, r;
queue<pair<int ,int>>to_merge;

int bfs(int x, int y) {
	queue<pair<int, int>>q;
	int ans = arr[x][y];
	q.push({ x,y });
	visited[x][y] = true;
	to_merge.push({ x,y });

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx<1 || ny<1 || nx>n || ny>n)continue;
			if (visited[nx][ny] || abs(arr[nx][ny] - arr[curX][curY]) < l || abs(arr[nx][ny] - arr[curX][curY]) > r) continue;
			visited[nx][ny] = true;
			to_merge.push({ nx,ny });
			q.push({ nx,ny });
			ans += arr[nx][ny];
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> l >> r;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	int idx = 0;
	while(1) {
		memset(visited, false, sizeof(visited));
		bool flag = false;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (!visited[i][j]) {
					
					int avg = bfs(i, j);
					if (to_merge.size()>1) {
						flag = true;
					}
					avg /= to_merge.size();
					while (!to_merge.empty()) {
						int x = to_merge.front().first;
						int y = to_merge.front().second;
						to_merge.pop();
						arr[x][y] = avg;
					}
				}
			}
		if (!flag) {
			cout << idx;
			return 0;
		}
		idx++;
	}

}
