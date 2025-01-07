#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 1;
		map<string, int>map;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string name, item;
			cin >> name >> item;
			map[item]++;
		}
		vector<pair<string, int>>v(map.begin(), map.end());

		for (int i = 0; i < v.size(); i++) {
			ans *= (v[i].second + 1);
		}
		cout << ans-1 << "\n";
		
	}
}
