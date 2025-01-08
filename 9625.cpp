#include <iostream>
using namespace std;

int main() {
	int a = 1, b = 0;
	int n;
	cin >> n;
	while (n--) {
		int toA = 0, toB = 0;

		toB += a;
		toB += b;
		toA += b;

		a = toA;
		b = toB;
	}

	cout << a << " " << b;
}
