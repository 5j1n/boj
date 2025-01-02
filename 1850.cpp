#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	long long c = a % b;
	if (c == 0) return b;
	return gcd(b, c);
}
int main() {
	long long n, m;
	cin >> n >> m;
	string ans = "";

	for (long long i = 0; i < gcd(n, m); i++)
		ans.push_back('1');

	cout << ans;
}
