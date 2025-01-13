#include <iostream>
#include <cstring>
using namespace std;

int dp[100001];

int main() {
	int n;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	dp[0] = 0;
	dp[2] = 1;
	dp[4] = 2;
	dp[5] = 1;

	for (int i = 6; i <= n; i++) {
		if (dp[i - 2] != -1)
			dp[i] = dp[i - 2] + 1;
		if (dp[i - 5] != -1)
			dp[i] = dp[i - 5] + 1;
	}

	cout << dp[n];

}
