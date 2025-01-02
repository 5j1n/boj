#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];

int main() {
	for (int i = 1; i <= 3; i++)
		dp[i] = i;

	int n;
	cin >> n;

	for (int i = 4; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		} 
	}

	cout << dp[n];
}
