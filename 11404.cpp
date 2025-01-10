#include <iostream>
#include <algorithm>
#define INF 0xfffffff

using namespace std;

int arr[101][101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	fill(arr[0], arr[101], INF);

	for (int i = 1; i <= n; i++)
		arr[i][i] = 0;

	for (int i = 0; i < m; i++) {
		int f, t, w;
		cin >> f >> t >> w;
		arr[f][t] = min(arr[f][t],w);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == INF) cout << "0 ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
