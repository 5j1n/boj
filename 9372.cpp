#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int>v[1001];
bool check[1001];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			check[i] = false;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int ret = 0;
		queue<int>q;
		q.push(1);
		check[1] = true;
		while (!q.empty()) {
			int idx = q.front();
			q.pop();
			for (int i = 0; i < v[idx].size(); i++) {
				int nxt = v[idx][i];
				if (!check[nxt]) {
					check[nxt] = true;
					ret++;
					q.push(nxt);
				}
			}
		}
		cout << ret << "\n";
	}
}
