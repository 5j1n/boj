#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501], dp[501][501];
int n, ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i - 1 > -1 && j - 1 > -1)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[n - 1][i]);
	cout << ans;
}
