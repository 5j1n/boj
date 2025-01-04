#include <iostream>
#define mod 1000000000
using namespace std;

long long n, k;
long long dp[201][201];

int main() {
	cin >> n >> k;

	for (long long i = 0; i <= n; i++)
		dp[1][i] = 1;

	for (long long i = 2; i <= k; i++) {
		for (long long j = 0; j <= n; j++) {
			for (long long m = 0; m <= j; m++) {
				dp[i][j] += dp[i - 1][m];
			}
			dp[i][j] %= mod;
		}
	}

	cout << dp[k][n];
}
