#include <iostream>
using namespace std;

int dp[21][21][21];

int recur(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	else if (a > 20 || b > 20 || c > 20) return recur(20, 20, 20);
	else if (dp[a][b][c] != 0) return dp[a][b][c];
	else if (a < b && b < c)
		dp[a][b][c] = recur(a, b, c - 1) + recur(a, b - 1, c - 1) - recur(a, b - 1, c);
	else
		dp[a][b][c] = recur(a - 1, b, c) + recur(a - 1, b - 1, c) + recur(a - 1, b, c - 1) - recur(a - 1, b - 1, c - 1);

	return dp[a][b][c];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b, c;

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) return 0;

		int ans = recur(a, b, c);

		cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
	}
}
