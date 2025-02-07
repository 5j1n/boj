#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int p[100001];
vector<pair<pair<int, int>, int>>v;

bool cmp(pair<pair<int, int>, int>a, pair<pair<int, int>, int>b) {
	return a.first.first < b.first.first;
}
int find(int x) {
	if (p[x] != x) return p[x] = find(p[x]);
	return p[x];
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a > b) p[a] = b;
	else if (a < b) p[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ {a,b},i });
	}
	sort(v.begin(), v.end(), cmp);
	int st = v[0].first.first;
	int en = v[0].first.second;
	int idx = v[0].second;
	for (int i = 1; i < n; i++) {
		int n_st = v[i].first.first;
		if (n_st <= en) {
			uni(idx, v[i].second);

		}
		else idx = v[i].second;
		en = max(en, v[i].first.second);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b)) cout << "1\n";
		else cout << "0\n";
	}
}
