#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, p[51];
vector<int>arr[51], people;

int find_set(int x) {
	if (p[x] != x) p[x] = find_set(p[x]);
	return p[x];
}

void uni(int a, int b) {
	int x = find_set(a);
	int y = find_set(b);

	if (x < y) p[y] = x;
	else p[x] = y;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;
		people.push_back(a);
	}
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		int b, c;
		for (int j = 0; j < a; j++) {
			cin >> c;
			arr[i].push_back(c);
			if (j == 0) {
				b = c;
				continue;
			}
			uni(b, c);
			b = c;
		}
	}
	int ans = 0;
	if (!num) cout << m;
	else {
		for (int i = 0; i < m; i++) {
			bool possible = true;
			for (int j = 0; j < arr[i].size(); j++) {
				int n = arr[i][j];
				for (int k = 0; k < people.size(); k++) {
					if (find_set(n) == find_set(people[k])) {
						possible = false;
						break;
					}
				}
				if (!possible) break;
			}
			if (possible) ans++;
		}

		cout << ans;
	}
}
