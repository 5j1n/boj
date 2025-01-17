#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int dp[50001];

int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int mini = INT_MAX;
		for (int j = 1; j * j <= i; j++)
		{
			int tmp = i - j * j;
			mini = min(mini, dp[tmp]);
		} 
		dp[i] = mini + 1;
	}

	cout << dp[n];
}
