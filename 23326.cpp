#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int cur;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	set<int>Set;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp) Set.insert(i);
	}
	while (m--) {
		int command;
		cin >> command;
		if (command == 1) {
			int num;
			cin >> num;
			if (Set.count(num - 1) == 0) {
				Set.insert(num - 1);
			}
			else Set.erase(num - 1);
		}
		else if (command == 2) {
			int num;
			cin >> num;
			cur += (num + n) % n;
			cur = (cur + n) % n;
		}
		else {
			if (Set.size() == 0) {
				cout << "-1\n";
			}
			else {
				auto idx = Set.lower_bound(cur);
				if (idx == Set.end()) {
					cout << *Set.begin() + n - cur << "\n";
				}
				else {
					int ans = *idx - cur;
					cout << ans << "\n";
				}
			}
		}
	}
}
