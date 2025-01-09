#include <iostream>
using namespace std;

int arr[1001][1001];

void com(int n, int k) {
	for (int i = 1; i <= n; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			arr[i][j] = (arr[i - 1][j - 1] % 10007 + arr[i - 1][j] % 10007) % 10007;
		}
	}
	cout << arr[n][k];
}
int main() {
	int n, k;
	cin >> n >> k;
	com(n, k);
}
