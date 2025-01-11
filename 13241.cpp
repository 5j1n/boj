#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	long long c = a % b;
	if (c == 0) return b;
	else return gcd(b, c);
}

int main() {
	long long a, b;
	cin >> a >> b;
	cout << a * b / gcd(a, b);
}
