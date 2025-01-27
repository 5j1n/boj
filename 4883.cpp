#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int arr[3][100001], dp[3][100001];

int main() {
	int idx = 1;
	while (1) {
		int n = 2;
		cin >> n;
		if (!n) break;
		memset(arr, 0, sizeof(arr));
		fill(&dp[0][0], &dp[0][0] + 3 * 100001, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[j][i];
			}
		}
		dp[0][0] = 9876543210;
		dp[1][0] = arr[1][0];
		dp[2][0] = arr[1][0] + arr[2][0];
		dp[0][1] = dp[1][0] + arr[0][1];
		dp[1][1] = min(dp[0][1],min(dp[1][0], dp[2][0])) + arr[1][1];
		dp[2][1] = min(dp[1][1], min(dp[1][0], dp[2][0])) + arr[2][1];

		for (int i = 1; i < n; i++) {
			dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]) + arr[0][i];
			dp[1][i] = min(min(dp[0][i - 1],dp[0][i]), min(dp[1][i - 1], dp[2][i - 1])) + arr[1][i];
			dp[2][i] = min(dp[1][i - 1], min(dp[2][i - 1],dp[1][i])) + arr[2][i];
		}

		cout << idx << ". " << dp[1][n - 1] << "\n";
		idx++;
		
	}
}
