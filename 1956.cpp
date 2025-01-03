#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

long long arr[401][401];
long long v, e, ret = INT_MAX;

int main() {
	cin >> v >> e;

	for (long long i = 1; i <= v; i++)
		for (long long j = 1; j <= v; j++)
			arr[i][j] = INT_MAX;

	for (long long i = 0; i < e; i++) {
		long long a, b, w;
		cin >> a >> b >> w;
		arr[a][b] = w;
	}

	for (long long k = 1; k <= v; k++) {
		for (long long i = 1; i <= v; i++) {
			for (long long j = 1; j <= v; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (long long i = 1; i <= v; i++)
		ret = min(ret, arr[i][i]);

	if (ret == INT_MAX) cout << -1;
	else cout << ret;
}
