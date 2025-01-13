#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	arr[1][1] = 1;
	for (int i = 2; i <= 1000; i++) {
		arr[i][1] = arr[1][i] = 1;
	}
	
	
	for (int i = 2; i <= m; i++) {
		for (int j = 2; j <= n; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i][j - 1] + arr[i - 1][j]) % 1000000007;
		}
	}

	cout << arr[m][n];
	
}
