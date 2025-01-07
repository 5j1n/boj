#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		pair<int, int> home, fair;

		cin >> n;
		cin >> home.first >> home.second;

		vector<pair<int, int>>store(n);
		vector<bool>visited(n, false);
		for (int i = 0; i < n; i++) {
			cin >> store[i].first >> store[i].second;
		}
		cin >> fair.first >> fair.second;

		queue<pair<int, int>>q;
		q.push({ home.first, home.second });
		bool possible = false;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < store.size(); i++) {
				if ((abs(store[i].first - x) + abs(store[i].second - y)) <= 1000) {
					if (!visited[i]) {
						visited[i] = true;
						q.push({ store[i].first,store[i].second });
					}
				}
			}

			if ((abs(fair.first - x) + abs(fair.second - y)) <= 1000) {
				possible = true;
				break;
			}
		}

		if (possible) cout << "happy\n";
		else cout << "sad\n";
	}
}
