#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[16];
int dp[16];
int n, ans = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i].first >> arr[i].second;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j].first + j <= i && i+arr[i].first<=n+1) {
				dp[i] = max(dp[i], arr[i].second + dp[j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}
