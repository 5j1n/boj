#include <iostream>
using namespace std;

char arr[64][64];
string ans;
int n;

void recur(int x, int y, int size) {
	
	if (size == 1) {
		ans += arr[x][y];
		return;
	}
	bool zero, one;
	zero = one = true;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] == '0') one = false;
			else zero = false;
			if (!zero && !one) break;
		}
		if (!zero && !one) break;
	}
	if (zero) {
		ans += '0';
		return;
	}
	if (one) {
		ans += '1';
		return;
	}

	int nxt = size / 2;
	ans += '(';
	recur(x, y, nxt);
	recur(x, y + nxt, nxt);

	recur(x + nxt, y, nxt);
	recur(x + nxt, y + nxt, nxt);

	ans += ')';
	
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	recur(0, 0, n);
	cout << ans;
}
