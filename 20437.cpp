	#include <iostream>
	#include <vector>
	#include <unordered_map>
	#include <climits>
	#include <algorithm>

	using namespace std;

	int main() {
		ios::sync_with_stdio(false);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--) {
			string str;
			int n, ans1 = INT_MAX, ans2 = 0;
			cin >> str;
			cin >> n;
			unordered_map<char, vector<int>>map;
			for (int i = 0; i < str.size(); i++)
				map[str[i]].push_back(i);
			for (auto it = map.begin(); it != map.end(); it++) {
				if (it->second.size() >= n) {
					for (int i = 0; i <= it->second.size() - n; i++) {
						ans1 = min(ans1, map[it->first][i + n - 1] - map[it->first][i] + 1);
						ans2 = max(ans2, map[it->first][i + n - 1] - map[it->first][i] + 1);
					}
				}
			}
			if (ans1 == INT_MAX || ans2 == 0) cout << "-1\n";
			else cout << ans1 << " " << ans2<<"\n";
		}
	}
