#include <iostream>

using namespace std;

long long l[10000], k, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long tmp, maxi = 0;
	cin >> k >> n;
	for (long long i = 0; i < k; i++) {
		cin >> tmp; l[i] = tmp;
		if (tmp > maxi) maxi = tmp;
	}
	long long left = 1, mid, div, ans = maxi;
	while (left <= maxi)
	{
		mid = (left + maxi) / 2; 
		div = 0;
		if (left == maxi) {
			for (long long i = 0; i < k; i++) div += (l[i] / mid);
			if (div >= n) ans = mid;
			else ans = mid - 1;
			break;
		}

		for (long long i = 0; i < k; i++) div += (l[i] / mid);
		if (div >= n) left = mid + 1;
		else maxi = mid;
	}
	cout << ans;
}
