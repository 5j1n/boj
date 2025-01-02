#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<pair<int, int>, int>>v;
int d[501];

void dfs(int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v.size(); j++) {
			int from = v[j].first.first;
			int to = v[j].first.second;
			int cost = v[j].second;

			if (d[from] + cost < d[to]) 
				d[to] = d[from] + cost;
		}
	}
	for (int j = 0; j < v.size(); j++) {
		int from = v[j].first.first;
		int to = v[j].first.second;
		int cost = v[j].second;

		if (d[from] + cost < d[to])
		{
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		v.clear();
		int a,b,c;
		cin >> a >> b >> c;
		memset(d, 0xfffffff, sizeof(d));

		for (int i = 0; i < b; i++) {
			int from, to, cost; 
			cin >> from >> to >> cost;
			v.push_back({ {from,to},cost });
			v.push_back({ {to,from},cost });
		}

		for (int i = 0; i < c; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			v.push_back({ {from,to},-cost });
		}

		dfs(a);
	}
}
