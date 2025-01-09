#include <iostream>
using namespace std;

int dp[21];

int main() {
	dp[1] = 1;
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];
}
