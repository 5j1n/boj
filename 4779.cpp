#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string str;

void recur(int start, int end) {
	if (end - start == 1) return;

	int mid = (end - start) / 3;
	for (int i = start + mid; i < end - mid; i++)
		str[i] = ' ';

	recur(start, start + mid);
	recur(end - mid, end);
}
int main() {
	int n;
	while (cin >> n) {
		str.clear();
		int tmp = pow(3, n);
		for (int i = 0; i < tmp; i++)
			str.push_back('-');

		recur(0, tmp);
		cout << str<<"\n";
	}
}
