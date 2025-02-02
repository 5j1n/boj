#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int>v;
bool is_prime[4000001];

int n, ans;
void prime(int n) {
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			v.push_back(i);
			int tmp = i;
			for (int j = 2 * tmp; j <= n; j += tmp) {
				is_prime[j] = false;
			}
		}
	}
}
int main() {
	cin >> n;
	memset(is_prime, true, sizeof(is_prime));
	prime(n);
	int st = 0, en = 0, sum;
	if (v.size() > 0) {
		sum = v[st];
	}
	while (en < v.size()) {
		if (sum == n) {
			ans++;
			if (en < v.size() - 1) {
				en++;
				sum += v[en];
			}
			else break;
		}
		else if (sum < n) {
			if (en < v.size() - 1) {
				en++;
				sum += v[en];
			}
			else break;
		}
		else {
			sum -= v[st];
			st++;
		}
	}
	cout << ans;
}
