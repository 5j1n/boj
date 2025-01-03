#include <iostream>
#include <queue>
using namespace std;

int p[1001];
int n, m;
priority_queue < pair<int, pair<int, int>>, vector < pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;

int find_set(int x) {
	if (p[x] != x) p[x] = find_set(p[x]);
	return p[x];
}

void uni(int a, int b) {
	int x = find_set(a);
	int y = find_set(b);

	if (x > y) p[x] = y;
	else p[y] = x;
}

int solve() {
	int ans = 0;
	while (!q.empty()) {
		bool finish = true;
		for (int i = 1; i <= n; i++) {
			if (p[i] != 1) {
				finish = false;
				break;
			}
		}
		if (finish) {
			return ans;
		}

		int cost = q.top().first;
		int a = q.top().second.first;
		int b = q.top().second.second;
		q.pop();
		if (find_set(a) != find_set(b)) {
			uni(a, b);
			ans += cost;
		}
	}
}
int main() {
	
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		q.push({ w,{a,b} });
	}

	cout<<solve();

}
