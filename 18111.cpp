#include <iostream>
#include <climits>
using namespace std;

int arr[501][501];

int main() {
	int n, m, b, time =INT_MAX, idx;
	cin >> n >> m >> b;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int k = 0; k <= 256; k++) {
		int tmp = 0;
		int tmpB = b;
		int build = 0, remove = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > k) { //제거해야한다면
					remove += arr[i][j] - k;
				}
				else if (arr[i][j] < k) { //추가해야한다면
					build += k - arr[i][j];
				}
			}
		}

		if (build > tmpB + remove) {
			tmp = INT_MAX;
		}
		else {
			tmp = 2 * remove + build;
		}

		if (time >= tmp) {
			time = tmp;
			idx = k;
		//	cout << time << " " << idx << " " << remove << " " << build << "\n";
		}
	}
	cout << time << " " << idx;
}
