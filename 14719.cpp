#include <iostream>
using namespace std;

int a, b, ans;
int arr[501];

int main() {
	cin >> a >> b;
	for (int i = 1; i <= b; i++)
		cin >> arr[i];

	for (int i = 2; i < b; i++) {
		int left = 0, right = 0;

		for (int j = 1; j < i; j++)
			left = max(left, arr[j]);
		for (int j = i + 1; j <= b; j++)
			right = max(right, arr[j]);
		int ret = min(left, right) - arr[i];
		if (ret >= 0) ans += ret;
	}
	cout << ans << "\n";
}
