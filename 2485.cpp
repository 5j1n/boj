#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001], d[100001];

int gcd(int a, int b) {
	int c = a % b;
	if (c == 0) return b;
	else return gcd(b, c);
}

int main() {
	int n, GCD = 0, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n - 1; i++) {
		d[i] = arr[i + 1] - arr[i];
	}
	GCD = d[0];

	for (int i = 1; i < n - 1; i++) {
		GCD = gcd(GCD, d[i]);
	}

	for (int i = 0; i < n - 1; i++)
		cnt += d[i] / GCD - 1;
	cout << cnt;
}
