#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n, sum = 0, ans = 0;
	cin >> n;
	for (long long i = 1;; i++) {
		sum += i;
		if (sum == n) {
			cout << i;
			return 0;
		}
		else if (sum > n) {
			cout << i - 1;
			return 0;
		}
	}

}
