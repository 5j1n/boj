#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001], dp[10001];

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i-1],max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]));
		
	}
	cout << dp[n];

}
