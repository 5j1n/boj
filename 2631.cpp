#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int arr[201], dp[201];

int main() {
	int n, ans = INT_MAX;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				ans = min(ans, n-dp[i]);
			}
		}
	}

	cout << ans;
	
}
