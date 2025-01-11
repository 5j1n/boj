#include <iostream>
#include <algorithm>
using namespace std;

int arr[2][7];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, maxi, ans;
	ans = 0;
	cin >> n >> maxi;
	for (int i = 0; i < n; i++) {
		int sex, grade;
		cin >> sex >> grade;
		arr[sex][grade]++;

	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 7; j++) {
			if (arr[i][j] % maxi==0)
				ans += arr[i][j] / maxi;
			else ans += arr[i][j] / maxi + 1;
		}
	}
	cout << ans;
}
