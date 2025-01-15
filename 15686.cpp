#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int arr[51][51], visited[51][51];
int n, m, max_case, ans = 987654321;
vector<pair<int, int>>v;
vector<int>vec;
void bfs() {
	for (int i = 0; i < max_case; i++) {
		int cnt = 0;
		int tmp = i;
		for (int j = v.size() - 1; j > -1; j--)
		{
			vec[j] = tmp % 2;
			if (vec[j] > 0) cnt++;
			tmp = tmp / 2;
		}
		if (cnt != m) continue;
		memcpy(visited, arr, sizeof(arr));
		for (int j = 0; j < v.size(); j++) {
			if (vec[j] == 0) {
				visited[v[j].first][v[j].second] = 0;
			}
		}
		int tmp_ans = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (visited[j][k] == 1) {
					int tmp_dist = 987654321;
					for (int l = 0; l < v.size(); l++) {
						if (visited[v[l].first][v[l].second] == 2) {
							//cout << v[l].first << " " << v[l].second << "\n";
							tmp_dist = min(tmp_dist, abs(v[l].first - j) + abs(v[l].second - k));
						}
					}
					tmp_ans += tmp_dist;
				}
			}
		}
		ans = min(ans, tmp_ans);

	}

}
int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	max_case = 1;
	vec.resize(v.size());
	for (int i = 0; i < v.size(); i++) {
		max_case *= 2;
	}
	bfs();
	cout << ans;
}
