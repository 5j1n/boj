#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

char arr[5][5];
bool dfs_visited[5][5], bfs_visited[5][5];
vector<pair<int, int>>candidate;
int ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool adj() {
	bool tmp_arr[5][5];
	memset(tmp_arr, false, sizeof(tmp_arr));
	memset(bfs_visited, false, sizeof(bfs_visited));
	for (int i = 0; i < 7; i++) {
		tmp_arr[candidate[i].first][candidate[i].second] = 1;
	}

	queue<pair<int, int>>q;
	int tmp = 1;
	q.push({ candidate[0].first,candidate[0].second });
	bfs_visited[candidate[0].first][candidate[0].second] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx>4 || ny>4) continue;
			if (bfs_visited[nx][ny]||!tmp_arr[nx][ny]) continue;
			bfs_visited[nx][ny] = true;
			q.push({ nx,ny });
			tmp++;
		}
	}
	if (tmp == 7) return true;
	return false;
}
void tracking(int idx, int cnt) {
	if (cnt == 7) {
		int s = 0;
		for (int i = 0; i < 7; i++) {

			if (arr[candidate[i].first][candidate[i].second] == 'S') s++;
		}
		if (s >= 4 && adj())ans++;
		return;
	}

	for (int i = idx; i < 25; i++) {
		if (!dfs_visited[i / 5][i % 5]) {
			dfs_visited[i / 5][i % 5] = true;
			candidate.push_back({ i / 5,i % 5 });
			tracking(i + 1, cnt + 1);
			dfs_visited[i / 5][i % 5] = false;
			candidate.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	tracking(0, 0);
	cout << ans;
}
