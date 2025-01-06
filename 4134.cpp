#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n;
	cin >> n;
	while (n--) {
		long long val;
		cin >> val;
		if (val < 2) {
			cout << 2 << "\n";
			continue;
		}
		for (long long i = val;; i++) {
			bool isPrime = true;
			for (long long j = 2; j * j <= i; j++) {
				if (i % j == 0)
				{
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				cout << i << "\n";
				break;
			}
		}
	}
}
