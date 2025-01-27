#include <iostream>

using namespace std;

long long dp[91];

int main() {
	dp[1] = 1;
	long long n;
	cin >> n;
	for (long long i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n];
}
