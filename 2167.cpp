#include <iostream>
using namespace std;

int arr[301][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, k, i, j, x, y;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	cin >> k;

	while (k--) {
		int sum = 0;
		cin >> i >> j >> x >> y;
		for (int a = i - 1; a < x; a++) {
			for (int b = j - 1; b < y; b++) {
				sum += arr[a][b];
			}
		}
		cout << sum << "\n";
	}
}
