#include <iostream>
using namespace std;

int arr[21], dp[10001];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		dp[0] = 1;
		int target;
		cin >> target;
		for (int i = 1; i <= n; i++) {
			for (int j = arr[i]; j <= target; j++)
				dp[j] += dp[j - arr[i]];
		}
		cout << dp[target] << "\n";
	}
}
