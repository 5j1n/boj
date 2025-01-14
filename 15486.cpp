#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int>arr[1500001];
int dp[1500001];

int main() {
	int n, ans;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	int maxi = 0;
	for (int i = 0; i <= n; i++) {
		maxi = max(maxi, dp[i]);
		if (i + arr[i].first > n) continue;
		dp[i + arr[i].first] = max(maxi + arr[i].second, dp[i + arr[i].first]);
		ans = maxi;
	}
	

	cout << ans;
}
