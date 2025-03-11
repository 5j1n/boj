#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long b, c, n, ans;

int main() {
	cin >> n;
	vector<long long>v(n);
	for (long long i = 0; i < n; i++)
		cin >> v[i];
	cin >> b >> c;

	for (long long i = 0; i < n; i++) {
		ans++;
		v[i] = max(v[i] - b, (long long) 0);

		if (v[i]) {
			ans += v[i] / c;
			if (v[i] % c) ans++;
		}
	}

	cout << ans;
}
