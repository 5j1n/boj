#include <iostream>
#include <algorithm>
using namespace std;

long long l, p, v;

int main() {
	long long idx = 1;
	while (1) {
		cin >> l >> p >> v;
		if (!l && !p && !v) break;
		cout << "Case "<<idx<<": " <<(v / p) * l + min(v % p,l)<<"\n";
		idx++;
	}
}
