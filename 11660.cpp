#include <iostream>
using namespace std;

int arr[1025][1025], dp[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++) {
		dp[1][i] = arr[1][i] + dp[1][i - 1];
		dp[i][1] = arr[i][1] + dp[i - 1][1];
	}
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];

	for (int i = 0; i < m; i++) {
		int st1, st2, en1, en2;
		cin >> st1 >> st2 >> en1 >> en2;
		cout << dp[en1][en2] - dp[st1 - 1][en2] - dp[en1][st2 - 1] + dp[st1 - 1][st2 - 1]<<"\n";
	}
	
}
