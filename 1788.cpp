#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int main() {
	unordered_map<long long, long long>dp;
	dp[0] = 0;
	dp[1] = 1;
	long long n;
	cin >> n;
	if (n < 0) {
		for (long long i = -1; i >= n; i--) {
			dp[i] = (dp[i + 2] - dp[i + 1]) % 1000000000;
		}

	}
	else {
		for (long long i = 2; i <= n; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
		}
	}
	if (dp[n] == 0) cout << "0\n";
	else if (dp[n] > 0) cout << "1\n";
	else cout << "-1\n";
	cout << abs(dp[n]);
}
