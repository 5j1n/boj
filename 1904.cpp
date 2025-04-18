#include <iostream>
using namespace std;

long long dp[1000001];

int main() {
	long long n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (long long i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] % 15746 + dp[i - 2] % 15746;
	}
	cout << dp[n] % 15746;

}
