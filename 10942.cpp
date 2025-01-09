#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[2001];
bool palin[2001][2001] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n - 1; i++) {
		palin[i][i] = true;
		if (arr[i] == arr[i + 1])
			palin[i][i + 1] = true;
	}

	palin[n][n] = true;

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (arr[i] == arr[j] && palin[i + 1][j - 1])
				palin[i][j] = true;
		}
	}

	int start, end, m;
	cin >> m;

	for (int i = 0; i<m; i++){
		cin >> start >> end;
		cout << palin[start][end] << "\n";
	}
}
