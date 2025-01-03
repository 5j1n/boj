#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<long long,long long> twofive(long long sum) {
	long long two = 0, five = 0;

	for (long long i = 2; i <= sum; i *= 2)
		two += sum / i;
	for (long long i = 5; i <= sum; i *= 5) {
		five += sum / i;
	}

	return{ two,five };
}

int main() {
	long long n, m, ans2, ans5;
	cin >> n >> m;

	ans2 = twofive(n).first - twofive(m).first- twofive(n - m).first;
	ans5 = twofive(n).second - twofive(m).second - twofive(n - m).second;

	cout << min(ans2, ans5);
}
