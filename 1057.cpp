#include <iostream>
using namespace std;

int n, a, b;

int func() {
	int round = 1;
	while (n) {
		if ((a + 1) / 2 == (b + 1) / 2)
			break;
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		round += 1;
		n /= 2;
	}

	if (!n) return -1;

	return round;
}
int main() {
	cin >> n;
	cin >> a >> b;

	cout << func();
}
