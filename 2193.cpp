#include <iostream>
using namespace std;

long long dp[91];
int main() {
	long long n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	for (long long i = 3; i <= n; i++)
		dp[i] = dp[i - 2] + dp[i - 1];
	cout << dp[n];
}
