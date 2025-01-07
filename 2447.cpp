#include <iostream>

using namespace std;

char arr[6500][6500];
int n;

void make_empty(int x, int y,int n) {
	for (int i = x + n / 3; i < x+2 * n / 3; i++)
		for (int j = y+n / 3; j < y+2 * n / 3; j++)
			arr[i][j] = ' ';
}
void recur(int x, int y, int size) {
	if (size == 3) {
		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (i == x + 1 && j == y + 1)
					arr[i][j] = ' ';
				else arr[i][j] = '*';
			}
		}
		return;
	}

	int nxt = size / 3;
	
	recur(x, y, nxt);
	make_empty(x, y, nxt);
	recur(x + nxt, y, nxt);
	make_empty(x+nxt, y, nxt);
	recur(x + 2 * nxt, y, nxt);
	make_empty(x+2*nxt, y, nxt);

	recur(x, y+nxt, nxt);
	make_empty(x, y+nxt, nxt);
	recur(x + nxt, y+nxt, nxt);
	make_empty(x+nxt, y + nxt, nxt);
	recur(x + 2 * nxt, y+nxt, nxt);
	make_empty(x+2*nxt, y + nxt, nxt);

	recur(x, y + 2*nxt, nxt);
	make_empty(x, y+2*nxt, nxt);
	recur(x + nxt, y +2* nxt, nxt);
	make_empty(x+nxt, y + 2 * nxt, nxt);
	recur(x + 2 * nxt, y + 2*nxt, nxt);
	make_empty(x+2*nxt, y + 2 * nxt, nxt);

	return;

}
int main() {
	cin >> n;

	recur(0,0,n);

	for (int i = n / 3; i <  2 * n / 3; i++)
		for (int j = n / 3; j < 2 * n / 3; j++)
			arr[i][j] = ' ';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}
