#include <iostream>
using namespace std;

int a[101][101], b[101][101], ans[101][101];

int main() {
	int n, m, k;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	cin >> m >> k;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= k; j++)
			cin >> b[i][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++) {
			for (int x = 1; x <= m; x++) {
				ans[i][j] += a[i][x] * b[x][j];
			}
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

}
