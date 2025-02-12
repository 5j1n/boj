#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int p[501], child_cnt[501];
set<int>cycled;
bool chk[501];
int find(int x) {
	if (p[x] != x) return p[x] = find(p[x]);
	return p[x];
}

int uni(int a, int b) {
	if (a > b) {
		p[a] = b;
		return child_cnt[a];
	}
	else if (a < b) {
		p[b] = a;
		return child_cnt[b];
	}
}
int main() {
	int idx = 1;
	while (1) {
		cycled.clear();
		memset(chk, false, sizeof(chk));
		int n, m;
		cin >> n >> m;
		int ans = n;
		if (!n && !m) break;
		memset(p, 0, sizeof(p));
		memset(child_cnt, 0, sizeof(child_cnt));
		
		for (int i = 1; i <= n; i++) {
			p[i] = i;
			child_cnt[i] = 1;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			a = find(a);
			b = find(b);
			if (a == b) {
				cycled.insert(a);
				cycled.insert(b);
			}
			else ans-=uni(a, b);
		}
		for (auto it = cycled.begin(); it != cycled.end(); it++) {
			int parent = find(*it);
			if (!chk[parent]) {
				chk[parent] = true;
				ans -= child_cnt[parent];
			}
		}
		cout << "Case " << idx << ": ";
		if (!ans) cout << "No trees.\n";
		else if (ans == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << ans << " trees.\n";

		idx++;
	}
}
