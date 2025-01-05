#include <iostream>
#include <algorithm>
using namespace std;

int dp[5001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		dp[i] = 987654321;
	dp[3] = dp[5] = 1;

	for (int i = 6; i <= n; i++) {
		dp[i] = min(dp[i], min(dp[i - 3] + 1, dp[i - 5] + 1));
	}

	if (dp[n] == 987654321) cout << -1;
	else cout << dp[n];
}
