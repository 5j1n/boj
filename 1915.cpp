#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1001][1001];
char tmp[1001][1001];

int main() {
	long long n, m, ans = 0;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		for (long long j = 1; j <= m; j++)
		{
			cin >> tmp[i][j];
			arr[i][j] = tmp[i][j] - '0';
			if (arr[i][j])ans = 1;
		}


	for (long long i = 2; i <= n; i++) {
		for (long long j = 2; j <= m; j++) {
			if (arr[i][j]) {
				arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;
				ans = max(ans, arr[i][j]);
			}

		}
	}

	cout << ans * ans;
}
