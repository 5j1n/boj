#include <iostream>
using namespace std;

long long arr[101];

int main() {
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	for (long long i = 6; i < 101; i++) {
		arr[i] = arr[i - 5] + arr[i - 1];
	}
	long long t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		cout << arr[n] << "\n";
	}
}
