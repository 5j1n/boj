#include <iostream>
using namespace std;

bool arr[1001];
int n, m;

void func(int n, int m) {
	int cnt = 0;

	for (int i = 2; i <= n; i++) {
		int tmp = i;
		while (tmp <= n) {
			if (!arr[tmp]) {
				arr[tmp] = true;
				cnt++;
			}
			if (cnt == m) {
				cout << tmp;
				return;
			}

			tmp += i;
		}
	}
}
int main() {
	cin >> n >> m;
	
	func(n, m);
}
