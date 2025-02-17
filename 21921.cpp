#include <iostream>
#include <algorithm>

using namespace std;

int arr[250001], sum[250001];
int n, x, maxi, ans;

int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = x; i <= n; i++) {
		if (maxi == sum[i] - sum[i - x])ans++;
		else if (maxi < sum[i] - sum[i - x]) {
			ans = 1;
			maxi = sum[i] - sum[i - x];
		}
	}
	if (!maxi) cout << "SAD";
	else {
		cout << maxi << "\n";
		cout << ans << "\n";
	}
}
