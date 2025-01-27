#include <iostream>

using namespace std;

long long arr[41];
long long fix[42];

int main() {
	long long n, m, ans = 1;
	cin >> n >> m;
	for (long long i = 1; i <= m; i++)
		cin >> fix[i];
	fix[m + 1] = n + 1;
	arr[1] = arr[0] = 1;
	arr[2] = 2;
	for (long long i = 3; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	for (long long i = 1; i <= m+1; i++) {
		cout << fix[i] << " ";
		ans *= arr[fix[i] - fix[i - 1] - 1];
	}
	cout << ans;
}
