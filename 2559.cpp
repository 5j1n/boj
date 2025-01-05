#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100001];
int main() {
	int n, m;
	cin >> n >> m;
	vector<int>ans(n - m + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= m; i++)
		ans[0] += arr[i];

	for (int i = m + 1; i <= n; i++) {
		ans[i - m] = ans[i - m - 1] + arr[i] - arr[i - m];
	}
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1];
}
