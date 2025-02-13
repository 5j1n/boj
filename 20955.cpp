#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int p[100001];
int ans;
unordered_set<int>set;

int find(int x) {
	if (p[x] != x) return p[x] = find(p[x]);
	return p[x];
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b) {
		p[a] = b;
		set.erase(a);
	}
	else if (a < b) {
		p[b] = a;
		set.erase(b);
	}
	else ans++;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		set.insert(i);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		uni(a, b);
	}
	cout << ans + set.size() - 1;
	
}
