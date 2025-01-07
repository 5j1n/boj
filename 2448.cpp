#include <iostream>
#include <string.h>

using namespace std;

const char tri[][5] = {
	' ', ' ', '*', ' ', ' ',
	' ', '*', ' ', '*', ' ',
	'*', '*', '*', '*', '*'
};

int n;
char arr[3100][6200];

void recur(int l, int x, int y) {
	if (l == 1) {
		for (int i = 0; i < 3; i++) 
			for (int j = 0; j < 5; j++)
			arr[x + i][y + j] = tri[i][j];

		return;
	}

	int t = 3 * l / 2;

	recur(l / 2, x, y + t);
	recur(l / 2, x + t, y);
	recur(l / 2, x + t, y + 2 * t);
}

int main() {

	cin >> n;
	memset(arr, ' ', sizeof(arr));
	recur(n / 3, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}
