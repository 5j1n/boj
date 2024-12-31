#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

ll ans;

void func(int x, int y, int n) {
	if (n == 0) return;
	int s = 1;
	for (int i = 0; i < n; i++)
		s *= 2;
	int z = s / 2 - 1;
	ll square = pow(s/ 2, 2);

	int nx, ny, nn;

	if (x <= z && y <= z) {
		nx = x;
		ny = y;
		ans += 0;
	}

	else if (x > z && y <= z) {
		nx = x - z - 1;
		ny = y;
		ans += square;
	}

	else if (x <= z && y > z) {
		nx = x;
		ny = y - z - 1;
		ans += 2 * square;
	}

	else {
		nx = x - z - 1;
		ny = y - z - 1;
		ans += 3 * square;
	}

	nn = n--;

	func(nx, ny, n--);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, x, y;
	cin >> n >> y >> x;
	func(x, y, n);
	cout << ans;
}
