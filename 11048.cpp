#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][1001], dp[1001][1001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++)
		dp[i][1] = dp[i - 1][1] + arr[i][1];
	for (int i = 2; i <= m; i++)
		dp[1][i] = dp[1][i - 1] + arr[1][i];

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1])) + arr[i][j];
		}
	}

	cout << dp[n][m];

}
