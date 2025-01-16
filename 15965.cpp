#include <iostream>
#include <cstdlib>
using namespace std;

int arr[7368788];
int num[500001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	fill(arr, arr + 7368788, 1);
	int n;
	cin >> n;
	int cnt = 1;
	arr[1] = 0;
	for (int i = 2; i <= 7368787; i++) {
		if (arr[i]) {
			num[cnt] = i;
			if (cnt == n) {
				cout << i;
				return 0;
			}
			cnt++;
			for (int j = 2; j * i <= 7368787; j++)
				arr[i * j] = 0;
		}
	}
}
