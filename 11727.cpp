#include <iostream>
using namespace std;

int dp[1001];

int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] % 10007 + dp[i - 2] %10007 * 2;
	}
	cout << dp[n] % 10007;
}
