#include <iostream>
using namespace std;

bool arr[10001];

int d(int n) {
	int tmp;
	tmp = n + n / 1000 + n % 1000 / 100 + n % 100 / 10 + n % 10;
	return tmp;
}

int main() {
	int tmp;
	arr[1] = false;
	for (int i = 0; i < 10000; i++) {
		if (i < 10000) {
			tmp = d(i);
			if (tmp < 10000)
				arr[tmp] = true;
		}
	}

	for (int i = 1; i < 10000; i++)
		if (!arr[i])
			cout << i << "\n";
}
