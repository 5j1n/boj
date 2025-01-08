#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b) {
	long long c = a % b;
	if (!c) return b;
	else return gcd(b, c);
}

int main() {
	long long t;
	cin >> t;
	while (t--) {
		vector<long long>v;
		long long n, ans=0;
		cin >> n;

		for (long long i = 0; i < n; i++) {
			long long tmp;
			cin >> tmp;
			v.push_back(tmp);
		}

		for (long long i = 0; i < n - 1; i++) {
			for (long long j = i+1; j < n; j++) {
				ans += gcd(v[i], v[j]);
			}
		}

		cout << ans<<"\n";
	}
}
