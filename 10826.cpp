#include <iostream>
#include <cstring>
#include <string>
#include <deque>

using namespace std;
string arr[10001];

int main() {
	int n;
	cin >> n;
	arr[0] = "0";
	arr[1] = "1";

	for (int i = 2; i <= n; i++) {
		deque<char>dq;
		if (arr[i - 1].size() == arr[i - 2].size()) {
			int carry = 0;
			for (int j = arr[i - 1].size() - 1; j > -1; j--) {
				int sum = arr[i - 1][j] - '0' + arr[i - 2][j] - '0' + carry;
				if (sum > 9) {
					carry = 1;
					dq.push_front((sum % 10) + '0');
				}
				else {
					carry = 0;
					dq.push_front((sum) + '0');
				}
			}
			if (carry) {
				dq.push_front('1');
			}
			
		}
		else {
			int carry = 0;
			for (int j = arr[i - 1].size() - 1; j > -1; j--) {
				int sum;
				if (j == 0) {
					sum = arr[i - 1][j] - '0' + carry;
				}
				else {
					sum = arr[i - 1][j] - '0' + arr[i - 2][j - 1] - '0' + carry;
				}
				if (sum > 9) {
					carry = 1;
					dq.push_front((sum % 10) + '0');
				}
				else {
					carry = 0;
					dq.push_front((sum)+'0');
				}
			}
			if (carry) dq.push_front('1');
		}
		string tmp = "";
		for (int i = 0; i < dq.size(); i++) {
			tmp += dq[i];
		}
		arr[i] = tmp;
	}
	cout << arr[n];
}
