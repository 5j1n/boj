#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[100001];

bool cmp(pair<pair<int, int>, pair<int, int>>a, pair<pair<int, int>, pair<int, int>>b) {
	if (a.first.first == b.first.first) {
		if (a.first.second == b.first.second) {
			if (a.second.first==b.second.first)
				return a.second.second > b.second.second;
			return a.second.first > b.second.first;
		}
		return a.first.second < b.first.second;
	}
	return a.first.first < b.first.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, ans = 0, checked = 0;
	cin >> n;
	vector<pair<pair<int, int>, pair<int, int>>>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
	sort(v.begin(), v.end(), cmp);

	int start = 301;
	while (start < 1200) {
		int val = 0, idx = 0;
		for (int i = checked; i < n; i++) {
			int cur_start = v[i].first.first * 100 + v[i].first.second;
			if (!visited[i] &&  cur_start<= start) {
				int tmp = v[i].second.first * 100 + v[i].second.second;
				checked++;
				if (val < tmp) {
					idx = i;
					val = tmp;
				}
			}
			else if (cur_start > start) break;
			
		}
		if (!val) {
			cout << "0";
			return 0;
		}
		visited[idx] = true;
		start = v[idx].second.first * 100 + v[idx].second.second;
		ans++;
	}
	cout << ans;
}
