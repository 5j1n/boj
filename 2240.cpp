#include <iostream>

using namespace std;

int t, w, ans = 0;
int arr[1001];
int dp[3][31][1001];

int main() {
	cin >> t >> w;
	for (int i = 1; i <= t; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));

	dp[1][w][0] = 0;

	for (int T = 0; T < t; T++) {
		for (int cnt = 0; cnt <= w; cnt++) {
			for (int p = 1; p <= 2; p++) {
				if (dp[p][cnt][T] != -1) {
					int nxt = arr[T + 1];

					if (p == nxt) {	
						dp[p][cnt][T + 1] = dp[p][cnt][T] + 1;
					}
					else {		
						if (cnt != 0) {	
							dp[nxt][cnt - 1][T + 1] = max(dp[nxt][cnt - 1][T + 1], dp[p][cnt][T] + 1);
						}				
						dp[p][cnt][T + 1] = dp[p][cnt][T];
					}
				};
			}
		}
	}

	int ans = 0;
	for (int p = 1; p <= 2; p++) {
		for (int i = 0; i <= w; i++) {
			ans = max(ans, dp[p][i][t]);
		}
	}
	cout << ans;
}
