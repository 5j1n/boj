#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n, m, h;
int ladder[31][11];
vector<pair<int, int>>candidate;
vector<bool>visited;

int dfs(int height, int st) {
	if (height == h + 1) {
		return st;
	}
	if (ladder[height][st] == 1) {
		return dfs(height + 1, st + 1);
	}
	else if (!ladder[height][st]) {
		return dfs(height + 1, st);
	}
	else return dfs(height + 1, st - 1);
}

bool check() {
	for (int i = 1; i <= n; i++) {
		if (dfs(1, i) != i) return false;
	}
	return true;
}

bool tracking(int idx, int cnt, int size) {
	if (cnt == size) return check();

	for (int i = idx; i < candidate.size(); i++) {
		if (!visited[i] && !ladder[candidate[i].first][candidate[i].second] && !ladder[candidate[i].first][candidate[i].second + 1]) {
			visited[i] = 1;
			ladder[candidate[i].first][candidate[i].second] = 1;
			ladder[candidate[i].first][candidate[i].second + 1] = -1;
			bool flag = tracking(i + 1, cnt + 1, size);
			if (flag) return true;
			visited[i] = 0;
			ladder[candidate[i].first][candidate[i].second] = 0;
			ladder[candidate[i].first][candidate[i].second + 1] = 0;
		}
	}
	return false;
}
int main() {
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
		ladder[a][b + 1] = -1;
	}

	if (check()) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n - 1; j++) {
			if (!ladder[i][j])
				candidate.push_back({ i,j });
		}
	}
	visited.resize(candidate.size());
	for (int i = 1; i <= 3; i++) {
		if (tracking(0, 0, i)) {

			cout << i;
			return 0;
		}
	}
	cout << -1;


}
