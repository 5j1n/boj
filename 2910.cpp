#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

long long n, m;

bool cmp(pair<long long, pair<long long, long long>>a, pair<long long, pair<long long, long long>>b) {
	if (a.second.second == b.second.second)
		return a.second.first < b.second.first;
	return a.second.second > b.second.second;
}
int main() {
	cin >> n >> m;
	long long tmp;
	unordered_map<long long, pair<long long, long long>>map;
	for (long long i = 0; i<n; i++) {
		cin >> tmp;
		if (map.find(tmp) != map.end()) {
			map[tmp].second++;
		}
		else map[tmp] = { i,1 };
	}
	vector<pair<long long, pair<long long, long long>>>v;

	for (auto it = map.begin(); it != map.end(); it++) {
		v.push_back({ it->first,{it->second.first,it->second.second} });
	}
	sort(v.begin(), v.end(), cmp);

	for (auto it = v.begin(); it != v.end(); it++) {
		for (long long i = 0; i < it->second.second; i++) {
			cout << it->first << " ";
		}
	}
}
