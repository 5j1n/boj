#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int arr[7][7], dp[7][7][3];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = arr[i][j];
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == 1) dp[i][j][0] = INT_MAX;
			else if (j == m) dp[i][j][2] = INT_MAX;

			if (j != 1) dp[i][j][0] += min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);
			if (j!=m)dp[i][j][2] += min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);

			dp[i][j][1] += min(dp[i - 1][j][0], dp[i - 1][j][2]);
		}
	}
	int ans = 987654321;
	for (int i = 1; i <= m; i++)
		for (int j = 0; j<3; j++)
			ans = min(ans, dp[n][i][j]);

	cout << ans;
	

}
