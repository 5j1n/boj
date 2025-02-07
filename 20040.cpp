#include <iostream>

using namespace std;

int p[500001];

int find(int x) {
	if (p[x] != x) return p[x] = find(p[x]);
	return p[x];
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a > b) p[a] = b;
	else p[b] = a;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b)) {
			cout << i + 1;
			return 0;
		}
		uni(a, b);
	}
	cout << 0;
}
