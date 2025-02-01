#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <string>
#include <unordered_set>

using namespace std;

vector<pair<long long , long long >>v[101];
int loc[1000001];
unordered_set<int>set;
string cop[101];
unordered_map<string, long long >map;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long  n, m;
	cin >> m >> n;
	for (long long  i = 0; i < m; i++) {
		memset(loc, 0, sizeof(loc));
		set.clear();
		for (long long  j = 0; j < n; j++) {
			long long  tmp, Rank;
			cin >> tmp;
			if (set.count(tmp) == 0) {
				loc[tmp] = j + 1;
				set.insert(tmp);
				Rank = j + 1;
			}
			else {
				Rank = loc[tmp];
			}
			v[i].push_back({ tmp ,Rank});
		}
		sort(v[i].begin(), v[i].end());
		for (long long  j = 0; j < n; j++) {
			if (v[i][j].second > 9) {
				string tmp = to_string(v[i][j].second);
				cop[i] += tmp;
			}
			else cop[i] += v[i][j].second + '0';
			cop[i] += " ";
		}
		//cout << cop[i] << "\n";
		map[cop[i]]++;
	}
	long long  ans = 0;
	for (auto it = map.begin(); it != map.end(); it++) {
		if (it->second > 1) ans += it->second * (it->second - 1) / 2;
	}
	cout << ans;
	
}
