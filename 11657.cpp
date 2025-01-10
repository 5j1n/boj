#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long n, m;
vector<pair<long long, long long>>v[501];

long long bell(long long s, long long e, vector<long long>& d) {
	d[s] = 0;
	for (long long i = 1; i <= e; i++) {
		for (long long cur = 1; cur <= e; cur++) {
			if (d[cur] == INT_MAX) continue;
			for (auto it = v[cur].begin(); it != v[cur].end(); it++) {
				long long nxt = it->first;
				long long nxtweight = it->second;
				if (d[nxt] > d[cur] + nxtweight) {
					d[nxt] = d[cur] + nxtweight;
					if (i == e) return -1;
				}
			}
		}
	}
	return 1;
}
int main() {
	cin >> n >> m;
	
	vector<long long>d(n + 1, INT_MAX);
	for (long long i = 0; i < m; i++) {
		long long s, e, weight;
		cin >> s >> e >> weight;
		v[s].push_back({ e,weight });
	}

	if (bell(1, n, d) != -1) {
		for (long long i = 2; i <= n; i++) {
			if (d[i] == INT_MAX) cout << -1;
			else cout << d[i];
			cout << "\n";
		}
	}

	else cout << "-1";
}
