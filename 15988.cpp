#include <iostream>
#define MOD 1000000009
using namespace std;

long long dp[1000001];

int main() {
	long long t;
	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (long long i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 3]%MOD+ dp[i - 2]%MOD+ dp[i - 1]%MOD)%MOD;
	}

	while (t--) {
		long long n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}
