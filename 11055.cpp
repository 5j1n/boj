#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001], dp[1001];

int main() {
	int n, ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
	}

	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}
