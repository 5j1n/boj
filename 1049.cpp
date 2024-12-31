#include <iostream>
#include <algorithm>
using namespace std;

int n, m, x, y;

int main() {
	int set = 987654321, single = 987654321;
	cin >> n >> m;

	while (m--) {
		cin >> x >> y;
		set = min(set, x);
		single = min(single, y);
	}


	cout << min((n / 6 + 1) * set, min(n/ 6 * set + n % 6 * single, n * single)) << '\n';
}
