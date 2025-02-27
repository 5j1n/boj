#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

long long arr[1001], dp[1001];

int main() {
	long long n;
	cin >> n;
	
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = INT_MAX;
	}

	dp[1] = 0;

	for (long long i = 1; i < n; i++) {
		for (long long j = i + 1; j <= min(i + arr[i], n); j++) {
			dp[j] = min(dp[j], dp[i] + 1);
		}
	}
	if (dp[n] == INT_MAX) cout << -1;
	else
		cout << dp[n];
}
