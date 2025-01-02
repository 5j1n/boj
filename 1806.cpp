#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];


int main() {
	int n, m, sum = 0, ans = 0xfffffff;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int left = 0, right = 0;
	sum = arr[0];
	while (left <= right && right<n) {
		if (sum < m) {
			right++;
			sum += arr[right];
		}
		else {
			ans = min(ans, right - left + 1);
			sum -= arr[left];
			left++;
		}
	}
	if (ans > n) ans = 0;
	cout << ans;
}
