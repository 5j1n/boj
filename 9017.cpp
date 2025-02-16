#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_map<int, int> candidate, victory;
vector<pair<int, int>>v;
unordered_set<int>to_remove;
int arr[1000], num[201];
int idx;

int main() {
	int t;
	cin >> t;
	while (t--) {
		candidate.clear();
		victory.clear();
		v.clear();
		idx = 0;
		to_remove.clear();
		memset(arr, 0, sizeof(arr));
		memset(num, 0, sizeof(num));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			candidate[arr[i]]++;
		}
		for (auto it = candidate.begin(); it != candidate.end(); it++)
		{
			if (it->second < 6) {
				to_remove.insert(it->first);
			}
		}
		for (int i = 0; i < n; i++) {
			if (!to_remove.count(arr[i]) && num[arr[i]] < 4) {
				victory[arr[i]] += i + 1 - idx;
				num[arr[i]]++;
			}
			else if (to_remove.count(arr[i])) idx++;
		}
		for (auto it = victory.begin(); it != victory.end(); it++) {
			v.push_back({ it->second,it->first });
			//cout << it->second << " " << it->first << "\n";
		}
		sort(v.begin(), v.end());

		if (v.size() == 1) cout << v[0].second << "\n";
		else {
			if (v[0].first == v[1].first) {
				unordered_set<int>real_candidate;
				for (int i = 0; i < v.size(); i++) {
					if (v[i].first == v[0].first)
						real_candidate.insert(v[i].second);
				}
				for (int i = 0; i < n; i++) {
					if (real_candidate.count(arr[i])) {
						num[arr[i]]++;
					}
					if (num[arr[i]] == 9)
					{
						cout << arr[i] << "\n";
						break;
					}
				}
			}
			else cout << v[0].second << "\n";
		}
	}
}
