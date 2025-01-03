#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n;
		vector<pair<int, int>>v;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}

		sort(v.begin(), v.end());

		int score = v[0].second;
		int cnt = 0;
		for (int i = 1; i < n; i++) {
			if (score <= v[i].second) cnt++;
			else score = v[i].second;
		}

		cout << n-cnt << "\n";
	}
}
