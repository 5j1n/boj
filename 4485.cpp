#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int arr[126][126], visited[126][126];
int n;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs() {
	priority_queue<pair<int, pair<int, int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
	pq.push({ arr[0][0],{0,0} });
	visited[0][0] = arr[0][0];

	while (!pq.empty()) {
		int curX = pq.top().second.first;
		int curY = pq.top().second.second;
		int dist = pq.top().first;
		pq.pop();
		if (curX == n - 1 && curY == n - 1) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] != -1) continue;
			pq.push({ dist + arr[nx][ny],{nx,ny} });
			visited[nx][ny] = dist + arr[nx][ny];
		}
	}
}
int main() {
	int idx = 1;
	while (1) {
		cin >> n;
		if (!n) break;
		memset(arr, 0, sizeof(arr));
		memset(visited, -1, sizeof(visited));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		bfs();

		cout << "Problem " << idx << ": " << visited[n - 1][n - 1] << "\n";
		idx++;
	}
}
