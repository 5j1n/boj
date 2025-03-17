#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <climits>
#include <deque>

using namespace std;

int n, m, d, removed, total, ans;
int arr[17][17];
bool visited[17];
deque<pair<int, int>>shooting;
vector<pair<int, int>>final_candidate;
bool cmp(pair<int, int>a, pair<int, int>b) {
	return a.second < b.second;
}
void shoot() {
	for (int s = 0; s < 3; s++) {
		pair<int, int>shooter = shooting[s];
		vector<pair<int, int>>candidate;
		int mini = INT_MAX;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int dist = abs(shooter.first - i) + abs(shooter.second - j);
				if (arr[i][j] && dist <= d) {
					if (mini == dist)
						candidate.push_back({ i,j });
					else if (mini > dist) {
						mini = dist;
						candidate.clear();
						candidate.push_back({ i,j });
					}
				}
			}
		}
		sort(candidate.begin(), candidate.end(), cmp);
		if (candidate.size()) {
			final_candidate.push_back({ candidate[0].first,candidate[0].second });
		}
	}

	for (int i = 0; i < final_candidate.size(); i++) {
		if (arr[final_candidate[i].first][final_candidate[i].second]) {
			removed++;
			total--;
			arr[final_candidate[i].first][final_candidate[i].second] = 0;
		}
	}
	final_candidate.clear();

}

void go() {
	for (int i = n - 1; i > -1; i--) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) {
				if (i == n - 1) {
					total--;
				}
				else {
					arr[i + 1][j] = 1;
				}
				arr[i][j] = 0;
			}
		}
	}

}

void dfs(int size) {
	if (size == 3) {
		int tmp = total;
		int tmp_arr[17][17];
		memcpy(tmp_arr, arr, sizeof(tmp_arr));
		while (total > 0) {
			shoot();
			go();
		}

		if (ans < removed) {
			ans = removed;
		}
		removed = 0;
		total = tmp;
		memcpy(arr, tmp_arr, sizeof(arr));
		return;
	}

	for (int i = 0; i < m; i++) {
		if (!visited[i]) {
			visited[i] = true;
			shooting.push_back({ n,i });
			dfs(size + 1);
			visited[i] = false;
			if (shooting.size()) shooting.pop_back();
		}
	}
	return;
}
int main() {
	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) total++;
		}
	}

	dfs(0);
	cout << ans;
}
