#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<pair<int, int>>v;// 내구도, 무게

void dfs(int k) {
	if (k == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].first <= 0)
				cnt++;
		}
		ans = max(cnt, ans);
		return;
	}
	if (v[k].first <= 0) dfs(k + 1);

	else {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (k!=i&&v[i].first > 0) {
				v[i].first -= v[k].second;
				v[k].first -= v[i].second;
				flag = true;
				dfs(k + 1);
				v[i].first += v[k].second;
				v[k].first += v[i].second;
			}
		}
		if (!flag) dfs(n);
	}
}
int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	dfs(0);
	cout << ans;

}
