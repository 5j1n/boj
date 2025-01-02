#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int p[100001];


int find_set(int x) {
	if (p[x] != x) p[x] = find_set(p[x]);
	return p[x];
}

void uni(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a > b) p[a] = b;
	else p[b] = a;
}

int main() {
	int n, m, ans = 0, last;
	cin >> n >> m;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
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
		
		if (find_set(a) != find_set(b)) {
			uni(a, b);
			//cout << a << " " << b << " " << w << "\n";
			ans += w;
			last = w;
		}
	}

	cout << ans - last;
}
