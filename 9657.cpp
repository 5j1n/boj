#include <iostream>
using namespace std;

int dp[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	dp[1] = dp[3] = dp[4] = dp[5] = 1;

	for (int i = 6; i <= n; i++) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0) dp[i] = 1;
		else dp[i] = 0;
	}

	if (dp[n]) cout << "SK\n";
	else cout << "CY\n";
}
