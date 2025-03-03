#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

int ans, n;
vector<int> arr, cnt;
int main(void) {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(0);

	cin >> n;
	arr.assign(n, 0);
	cnt.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		double maxi = -INT_MAX;
		for (int j = i + 1; j < n; j++) {
			double tmp = (double)(arr[j] - arr[i]) / (j - i);
			if (tmp > maxi) {
				maxi = tmp;
				cnt[i]++;
				cnt[j]++;
			}
		}
	}

	for (int i = 0; i<n; i++)
		ans = max(ans, cnt[i]);
	cout << ans << '\n';
}
