#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int>v(n + 1);
	vector<int>dp(n + 1, 987654321);
	dp[0] = 0;

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + v[j]);
		}
	}

	cout << dp[n];
}
