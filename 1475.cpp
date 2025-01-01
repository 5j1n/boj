#include <iostream>
#include <string>
using namespace std;
#define ll long long
	
int arr[9];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str;
	int maxi = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '9')
			arr[6]++;
		else
			arr[str[i] - '0']++;
	}

	for (int i = 0; i < 9; i++) {
		if (i == 6) {
			if (arr[i] % 2 == 1 && arr[i] / 2 + 1 > maxi)
				maxi = arr[i] / 2 + 1;
			else if (arr[i] % 2 == 0 && arr[i] / 2 > maxi) {
				maxi = arr[i] / 2;
			}
		}
		else {
			if (arr[i] > maxi)
				maxi = arr[i];
		}
	}
	cout << maxi;
}
