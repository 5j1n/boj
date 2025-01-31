#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long  n, m;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	set<long long >set;
	for (long long i = 0; i < n; i++) {
		long long  tmp;
		cin >> tmp;
		set.insert(tmp);
	}
	while (m--) {
		long long  tmp;
		cin >> tmp;
		if (set.count(tmp) > 0) set.erase(tmp);
	}
	vector<int>v;
	for (auto it = set.begin(); it != set.end(); it++) {
		v.push_back(*it);
	}
	cout << v.size() << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}
