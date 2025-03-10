#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1001], dp[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[0] = arr[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}

	cout << dp[n];
}
