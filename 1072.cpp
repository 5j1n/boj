#include <iostream>
using namespace std;

long long cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long x, y, z;
	cin >> x >> y;
	z = y * 100 / x;
	long long tmp = z;

	if (z >= 99) {
		cnt = -1;
		cout << cnt;
		return 0;
	}
	int left = 0, right = 1000000000;

	while (left <= right) {
		int mid = (left + right) / 2;
		int tmp = (y + mid) * 100 / (x + mid);

		if (z < tmp) right = mid - 1;
		else left = mid + 1;
	}
	cout << left;
}
