#include <iostream>
#include <cstring>
using namespace std;

bool prime[10001] = { true, };

void setting() {
	memset(prime, true, sizeof(prime));
	for (int i = 2; i <= 10000; i++) {
		if (prime[i]) {
			int tmp = i * 2;
			while (tmp <= 10000) {
				prime[tmp] = false;
				tmp += i;
			}
		}
	}
}

int main() {
	setting();
	int t;
	cin >> t;
	while (t--) {
		int n, ans1, ans2;
		cin >> n;
		for (int i = n/2; i >= 2; i--) {
			if (prime[i] && prime[n - i]) {
				ans1 = i;
				ans2 = n - i;
				cout << ans1 << " " << ans2 << "\n";
				break;
			}
		}
		
	}
}
