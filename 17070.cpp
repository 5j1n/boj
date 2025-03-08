#include <iostream>
#include <queue>

using namespace std;

int arr[17][17], dp[17][17][3];
int n;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	dp[1][2][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!arr[i][j]) {
				if (i - 1 > 0 && j - 1 > 0 && !arr[i-1][j] && !arr[i][j-1]) dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
				if (j - 1 > 0) dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
				if (i - 1 > 0) dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
			}
		}
	}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}
