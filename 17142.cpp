#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <climits>
#include <deque>

using namespace std;

int arr[51][51], visited[51][51];
bool already[11];
int n, m, ans = INT_MAX;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<pair<int, int>>virus;
deque<pair<int, int>>on;
deque<int>candidate;
int tmp;

int bfs() {
	int ret = 0;
	memset(visited, -1, sizeof(visited));
	queue<pair<int, pair<int,int>>>q;
	for (int i = 0; i < m; i++)
	{
		q.push({ 0,on[i] });
		visited[on[i].first][on[i].second] = 0;
	}

	while (!q.empty()) {
		int dist = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>n)continue;
			if (visited[nx][ny] != -1) continue;
			if (arr[nx][ny]!=1) {
				q.push({ dist + 1,{nx,ny} });
				visited[nx][ny] = dist + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!arr[i][j]) {
				ret = max(visited[i][j], ret);
			}
			if (!arr[i][j] && visited[i][j] == -1) {
				return INT_MAX;
				
			}
		}
	}
	return ret;
}
void dfs(int size, int idx) {
	if (size == m) {
		tmp++;
		int time = bfs();
		
		ans = min(time, ans);
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		if (!already[i]) {
			already[i] = true;
			on.push_back(virus[i]);
			dfs(size + 1, i+1);
			already[i] = false;
			on.pop_back();
		}
	}
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				virus.push_back({ i,j });
		}
	}

	dfs(0, 0);
	if (ans == INT_MAX) cout << "-1\n";
	else cout << ans;
}
