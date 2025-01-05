#include <iostream>
using namespace std;

int arr[101];
int ans;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int tmp = arr[n];

	for (int i = n - 1; i > 0; i--) {
		tmp--;
		if (tmp < arr[i]) {
			ans += arr[i] - tmp;
		}
		else {
			tmp = arr[i];
		}
	}

	cout << ans;
}
