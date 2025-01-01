#include <iostream>
#include <algorithm>
using namespace std;

int cnt0, cnt1;
bool zero, one;
int main() {
	string str;
	cin >> str;

	if ((str[0]-'0')) one = true;
	else zero = true;
	for (int i = 1; i < str.length(); i++) {
		if ((str[i]-'0') && zero) {
			cnt0++;
			zero = false;
			one = true;
		}
		else if (!(str[i]-'0') && one) {
			cnt1++;
			zero = true;
			one = false;
		}
	}
	if (zero) cnt0++;
	else if (one) cnt1++;

	cout << min(cnt0, cnt1);
}
