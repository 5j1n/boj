#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int cnt = 1, tmp = 1;
		while (1) {
			if (tmp % n == 0) break;
			cnt++;
			tmp = tmp * 10 + 1;
			tmp = tmp % n;
		}

		cout << cnt<<"\n";
	}
}
