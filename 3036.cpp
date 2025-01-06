#include <iostream>
using namespace std;

int n, arr[101];

int gcd(int a, int b) {
	int c = a % b;
	if (!c) return b;
	else return gcd(b, c);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int my = arr[1];
	for (int i = 2; i <= n; i++) {
		int tmp = gcd(my, arr[i]);
		cout << my / tmp << "/" << arr[i] / tmp << "\n";
	}
}
