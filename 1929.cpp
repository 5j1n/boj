#include <iostream>
using namespace std;

int prime[1000001];

int main() {
	int n, m;
	cin >> m >> n;

	for (int i = 2; i <= n; i++)
		prime[i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = i * 2; j <= n; j += i)
			prime[j] = 0;
	}
	for (int i = m; i <= n; i++)
		if (prime[i] == 1) cout << i << "\n";
}
