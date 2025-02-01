#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long >a, b, sumA, sumB;
long long  t, n, m, ans;
int main() {
	cin >> t;
	cin >> n;
	for (long long  i = 0; i < n; i++) {
		long long  tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	cin >> m;
	for (long long  i = 0; i < m; i++) {
		long long  tmp;
		cin >> tmp;
		b.push_back(tmp);
	}

	for (long long  i = 0; i < n; i++) {
		long long  tmp = a[i];
		sumA.push_back(tmp);
		for (long long  j = i + 1; j < n; j++) {
			tmp += a[j];
			sumA.push_back(tmp);
		}
	}
	for (long long  i = 0; i < m; i++) {
		long long  tmp = b[i];
		sumB.push_back(tmp);
		for (long long  j = i + 1; j < m; j++) {
			tmp += b[j];
			sumB.push_back(tmp);
		}
	}
	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end());

	for (long long  i = 0; i < sumA.size(); i++) {
		long long  target = t - sumA[i];
		long long  idx1 = lower_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
		long long  idx2 = upper_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
		ans += idx2 - idx1;
	}
	cout << ans;
}
