#include <iostream>
#include <climits>
using namespace std;

long long n, m;
long long arr[501][501];

int main() {
	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			arr[i][j] = INT_MAX;
		}
	}

	for (long long i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (long long k = 1; k <= n; k++) {
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		long long cnt = 0;
		for (long long j = 1; j <= n; j++) {
			if (arr[i][j] != INT_MAX || arr[j][i] != INT_MAX)
			{
				cnt++;
			}
		}
		if (cnt == n - 1) ans++;
	}

	cout << ans;
}
