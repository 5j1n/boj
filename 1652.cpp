#include <iostream>
using namespace std;

int n, arr[101][101];
int ans1, ans2;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmp;
			cin >> tmp;
			if (tmp == '.') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
	
	int tmp1 = 0, tmp2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) tmp1++;
			else tmp1 = 0;

			if (tmp1 == 2) ans1++;
		}

		tmp1 = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j][i]) tmp2++;
			else tmp2 = 0;

			if (tmp2 == 2) ans2++;
		}

		tmp2 = 0;
	}

	cout << ans1 << " " << ans2;
}
