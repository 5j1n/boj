#include <iostream>
using namespace std;

int n, b, w, arr[128][128];

void recur(int y, int x, int size) {
	int check = arr[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (!check && arr[i][j] == 1)
				check = 2;
			else if (check == 1 && arr[i][j] == 0)
				check = 2;
			if (check == 2) {
				recur(y, x, size / 2);
				recur(y, x + size / 2, size / 2);
				recur(y + size / 2, x, size / 2);
				recur(y + size / 2, x + size / 2, size / 2);
				return;
			}
		}
	}

	if (!check)
		w++;
	else
		b++;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	int check = arr[0][0];
	recur(0, 0, n);

	cout << w << "\n" << b;
}
