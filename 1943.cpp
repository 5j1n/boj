#include <iostream>
#include <cstring>

using namespace std;

pair<int, int> arr[101];
int dp[50001];

int main() {
	for (int t = 0; t < 3; t++) {
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int n, sum = 0;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
			sum += arr[i].first * arr[i].second;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 50000; j >= 0; j--) {
				if (j - arr[i].first >= 0) {
					if (dp[j - arr[i].first]) {
						for (int k = 0; k < arr[i].second; k++) {
							if (j + k * arr[i].first > sum/2) continue;
							dp[j + k * arr[i].first]++;
						}
					}
				}
			}
		}
		if (sum%2==0&&dp[sum / 2]) cout << "1\n";
		else cout << "0\n";
	}
}
