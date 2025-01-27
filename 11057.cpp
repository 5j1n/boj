#include <iostream>
using namespace std;

int dp[10][1001];
int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < 10; i++)
		dp[i][1] = 1;
	for (int j = 2; j <= n; j++) {
		for (int k = 0; k < 10; k++) {
			int tmp = 0;
			for (int l = 0; l <= k; l++) {
				tmp = (tmp + dp[l][j-1])%10007;
			}
			dp[k][j] = tmp;
		}
	}
	for (int i = 0; i < 10; i++) {
		ans = (ans + dp[i][n])%10007;
	}
	cout << ans;
}
