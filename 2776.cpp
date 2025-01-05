#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set<int>set;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			set.insert(tmp);
		}

		cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			if (set.count(tmp)) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
}
