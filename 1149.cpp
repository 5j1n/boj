#include <iostream>
#include <algorithm>
using namespace std;

int arr[4][1001], dp[4][1001];

int main() {
	int n, ans = 0xfffffff;
	cin >> n;
	for (int i = 1; i<=n; i++)
		for (int j = 1; j <= 3; j++) {
			cin >> arr[j][i];
		}
	for (int i = 1; i <= 3; i++)
		dp[i][1] = arr[i][1];

	for (int i = 2; i <= n; i++)
	{
		dp[1][i] = min(dp[2][i - 1], dp[3][i - 1]) + arr[1][i];
		dp[2][i] = min(dp[1][i - 1], dp[3][i - 1]) + arr[2][i];
		dp[3][i] = min(dp[1][i - 1], dp[2][i - 1]) + arr[3][i];
	}

	for (int i = 1; i <= 3; i++) {
		ans = min(ans, dp[i][n]);
	}
	cout << ans;

}
