#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp[10001];

int main() {
	fill(dp, dp + 10001, 987654321);
	int n, k;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (v[i]<=10000){
            dp[v[i]] = 1;
        }
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i - v[j] > 0) {
				dp[i] = min(dp[i], dp[i - v[j]] + 1);
			}
		}
	}

	if (dp[k] == 987654321) cout << -1;
	else cout << dp[k];

}
