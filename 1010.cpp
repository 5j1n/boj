#include <iostream>

using namespace std;
using ll = long long;
int tmp;
ll combi(int x, int y) {
	ll res = 1;
	for (int i = x; i > x - y; --i) {
		res = res * i;
		res = res / tmp++;
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		tmp = 1;
		ll a, b;
		cin >> a >> b;
		cout << combi(b, a)<<"\n";
	}
}
