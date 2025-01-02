#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int c = a % b;
	if (c == 0) return b;
	return gcd(b, c);
}

int main() {
	long long x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int a = (x1 * y2 + x2 * y1);
	int b = y1 * y2;
	cout << a / gcd(a, b) << " " << b / gcd(a, b);
}
