#include <iostream>
using namespace std;
int n, a[26][2];

void pre(int x) {
	if (x == -1) return;
	cout << char(x + 'A');
	pre(a[x][0]);
	pre(a[x][1]);
}

void in(int x) {
	if (x == -1) return;
	in(a[x][0]);
	cout << char(x + 'A');
	in(a[x][1]);
}

void post(int x) {
	if (x == -1) return;
	post(a[x][0]);
	post(a[x][1]);
	cout << char(x + 'A');
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;
		if (left == '.') a[parent - 'A'][0] = -1;
		else a[parent - 'A'][0] = left - 'A';
		if (right == '.') a[parent - 'A'][1] = -1;
		else a[parent - 'A'][1] = right - 'A';
	}

	pre(0);
	cout << "\n";
	in(0);
	cout << "\n";
	post(0);
}
