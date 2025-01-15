#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k, ans;
int truck[1001], time[1001];

void solve() {
	int in = 1, out = 1, total = 0;
	queue<int>q;
	while (1) {
		ans++;
		for (int i = out; i < min(n,in); i++) {
			if (ans-time[i] == m) {
				q.pop();
				//cout << "out: " << truck[out] << " at " << ans << "\n";
				total -= truck[out];
				out++;		
				
			}
		}
		if (in <= n && total + truck[in] <= k) {
			q.push(truck[in]);
			//cout << "in: " << truck[in] << " at " << ans << "\n";
			total += truck[in];
			time[in] = ans;
			in++;
		}
		if (out == n) break;
		
	}
	ans += m - ans + time[out];
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> truck[i];
	solve();
	cout << ans;
}
