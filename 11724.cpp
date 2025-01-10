#include <iostream>
#include <set>
using namespace std;

int p[1001];

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
	int n, m;
	set<int>set;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		uni(a, b);
	}
	for (int i = 1; i <= n; i++) {
		set.insert(find_set(i));
	}
	cout << set.size();
}
