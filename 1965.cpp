#include<iostream>
#include <algorithm>
using namespace std;

int dp[1001], arr[1001];

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);		
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
