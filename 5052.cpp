#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<string>v;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			v.push_back(str);
		}
		sort(v.begin(), v.end());
		bool possible = true;
		for (int i = 0; i < n - 1; i++) {
			int l = v[i].length();
			int nxtl = v[i + 1].length();

			if (l >= nxtl)
				continue;
			if (v[i + 1].substr(0, l) == v[i]) {
				possible = false;
				break;
			}
		}

		if (possible) cout << "YES\n";
		else cout << "NO\n";
	}
}
