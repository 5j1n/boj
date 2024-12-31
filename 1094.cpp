#include <iostream>
#include <cmath>
using namespace std;

int arr[7];

int main() {
	int n, ans = 0;
	cin >> n;

	for (int i = 6; i >= 0; i--) {
		if (pow(2, i) <= n) {
			arr[i] = 1;
			n -= pow(2, i);
			ans++;
		}
	}
	cout << ans;
}
