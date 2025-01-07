#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct medal {
	int num, gold, silver, bronze;
};

int compare(medal& x, medal& y) {
	if (x.gold == y.gold) {
		if (x.silver == y.silver) {
			if (x.bronze == y.bronze) return x.num < y.num;
			return x.bronze > y.bronze;
		}
		return x.silver > y.silver;
	}
	return x.gold > y.gold;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	vector<medal>v;
	unordered_map<string, int>map;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int c, g, s, b;
		cin >> c >> g >> s >> b;
		v.push_back({ c,g,s,b });
	}

	sort(v.begin(), v.end(), compare);

	int rank = 0, cnt = 1;
	vector<pair<int, int>>res;

	for (int i = 0; i < n; i++) {
		string str = to_string(v[i].gold) + to_string(v[i].silver) + to_string(v[i].bronze);

		if (!map[str]) {
			map[str] = v[i].num;
			res.push_back({ v[i].num, rank + cnt });
			rank += cnt;
			cnt = 1;
		}
		else {
			res.push_back({ v[i].num,rank });
			cnt++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (res[i].first == k) {
			cout << res[i].second;
			return 0;
		}
	}
}
