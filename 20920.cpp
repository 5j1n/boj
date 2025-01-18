#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

bool compare(pair<string, int>a, pair<string, int>b) {
	if (a.second == b.second) {
		if (a.first.length() == b.first.length()) {
			return a.first < b.first;
		}
		return a.first.length() > b.first.length();
	}
	return a.second > b.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	unordered_map<string, int>map;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str.length() >= m) {
			map[str]++;
		}
	}
	vector<pair<string, int>>v(map.begin(), map.end());
	sort(v.begin(), v.end(), compare);

	for (auto it = v.begin(); it != v.end(); it++)
		cout << it->first << "\n";
}
