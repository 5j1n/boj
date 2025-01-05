#include <iostream>

using namespace std;

int p[101];

void make_set(int x) {
	p[x] = x;
}

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
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		make_set(i);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		uni(a, b);
	}

	for (int i = 2; i <= n; i++) {
		if (find_set(i) == 1) ans++; 
	}
	cout << ans;
}
