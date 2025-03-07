#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

vector<pair<int, int>>v;
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
unordered_set<int>set;

int p[2000];

int find(int x) {
	if (p[x] != x) return p[x] = find(p[x]);
	return p[x];
}

void uni(int a, int b) {
	if (a > b) {
		p[a] = b;
		set.erase(a);
	}
	else {
		p[b] = a;
		set.erase(b);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	bool flag = false;
	int n, c, ans = 0;
	cin >> n >> c;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		p[i] = i;
		set.insert(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				int tmp = pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2);
				if (tmp >= c)
					pq.push({ tmp,{i,j} });
			}
		}
	}

	while (!pq.empty()) {
		int dist = pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();

		if (dist < c) continue;
		if (set.size() == 1) {
			flag = true;
			break;
		}

		a = find(a);
		b = find(b);

		if (a == b) continue;
		uni(a, b);
		ans += dist;
	}

	if (flag) cout << ans;
	else cout << -1;
}
