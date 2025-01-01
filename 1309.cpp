#include <iostream>
using namespace std;

int dp[100001] = { 1,3 };

int main() {
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}

	cout << dp[n];
}
