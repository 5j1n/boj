#include <iostream>
#include <cstring>
using namespace std;

bool arr[1000001];

void setting() {
	arr[0] = false; arr[1] = false;

	for (int i = 2; i <= 1000000; i++) {
		if (arr[i]) {
			for (int k = 2; k * i <= 1000000; k++) {
				arr[k * i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(arr, true, sizeof(arr));
	setting();
	while (1) {
		int n;
		cin >> n;
		if (!n) return 0;
		for (int i = 1; i <= n / 2; i++) {
			if (arr[i] == true && arr[n - i] == true)
			{
				cout << n << " = " << i << " + " << n - i << "\n";
				break;
			}
		}
	}
}
