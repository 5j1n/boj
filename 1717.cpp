#include <iostream>
using namespace std;
int p[1000001];

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 0; i < m; i++) {
		int c, a, b;
		cin >> c >> a >> b;
		if (!c) uni(a, b);
		else {
			if (find_set(a) == find_set(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
