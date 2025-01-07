#include <iostream>
#include <cstring>
using namespace std;
int arr[3][100001], dp[4][100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		int n;
		cin >> n;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 1; i < 3; i++)
			dp[i][1] = arr[i][1];

		for (int i = 2; i <= n; i++) {
			dp[1][i] = max(dp[2][i - 1], dp[3][i - 1]) + arr[1][i];
			dp[2][i] = max(dp[1][i - 1], dp[3][i - 1]) + arr[2][i];
			dp[3][i] = max(dp[1][i - 1], dp[2][i - 1]);
		}

		cout << max(dp[1][n], max(dp[2][n], dp[3][n])) << "\n";
	}
}
