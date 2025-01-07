#include <iostream>

using namespace std;

int dp[12];

int main() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int t;
	cin >> t;
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}
