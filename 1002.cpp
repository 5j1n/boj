#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, x1, y1, r1, x2, y2, r2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int d = pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
		if (d == 0) {
			if (pow(abs(r1 - r2), 2)) cout << "0\n";
			else cout << "-1\n";
		}
		else if (d == pow(abs(r1 - r2), 2) || d == pow(abs(r1 + r2), 2)) {
			cout << "1\n";
		}
		else if (pow(abs(r1 - r2), 2) < d && d < pow(abs(r1 + r2), 2))
			cout << "2\n";
		else cout << "0\n";
	}
}
