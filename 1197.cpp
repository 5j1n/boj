#include <iostream>
#include <queue>

using namespace std;

int p[10001];
priority_queue < pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>>>q;
int find_set(int x) {
	if (p[x] != x) p[x] = find_set(p[x]);
	return p[x];
}

bool uni(int a, int b) {
	int x = find_set(a);
	int y = find_set(b);
	if (x == y) return false;
	else {
		if (x > y)
			p[x] = y;
		else
			p[y] = x;
		return true;
	}
}

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		q.push({ w,{a,b} });
	}
	while (!q.empty()) {
		int w = q.top().first;
		int a = q.top().second.first;
		int b = q.top().second.second;
		q.pop();
		if (uni(a, b)) ans += w;
	}
	cout << ans;
}
