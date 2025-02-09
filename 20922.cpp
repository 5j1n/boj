#include <iostream>
#include <algorithm>

using namespace std;

int sum[100001], arr[200001], ans;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < n && sum[arr[j]] < m) {
			sum[arr[j]] ++;
			j++;
		}
		ans = max(ans,j - i);
		if (j == n) break;
		sum[arr[i]]--;
		
	}
	cout << ans;
}
