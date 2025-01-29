#include <iostream>

using namespace std;

bool prime[1001];

void find_prime() {
	prime[0] = prime[1] = true;
	for (int i = 2; i < 1001; i++) {
		if (!prime[i]) {
			int tmp = i * 2;
			while (tmp < 1001) {
				prime[tmp] = true;
				tmp += i;
			}
		}
	}
}

int main() {
	find_prime();
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (!prime[tmp]) ans++;
	}
	cout << ans;
}
