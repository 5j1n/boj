#include <iostream>
using namespace std;

int main() {
	int n, cnt = 99;

	cin >> n;
	if (n < 100) cnt = n;
	for (int i = 100; i <= n; i++) {
		int left = i / 100;
		int mid = i / 10 % 10;
		int right = i % 10;

		if (2 * mid == left + right) cnt++;
		
	}
	cout << cnt;
}
