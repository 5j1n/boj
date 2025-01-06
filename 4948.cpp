#include <iostream>
using namespace std;

bool arr[123456 * 2 + 1];

void setting() {
	arr[1] = true;
	for (int i = 2; i <= 123456 * 2; i++) {
		if (!arr[i]) {
			for (int j = 2; i * j <= 123456 * 2; j++) {
				arr[i * j] = true;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	setting();

	while (1) {
		int n, cnt = 0;
		cin >> n;
		if (!n) return 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (!arr[i]) cnt++;
		}
		cout << cnt << "\n";

	}
}
