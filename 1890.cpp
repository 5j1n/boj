#include <iostream>
#include <queue>
using namespace std;

long long arr[101][101], dp[101][101];

int main() {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j++)
            cin >> arr[i][j];
    }
    dp[1][1] = 1;
    
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j++) {
            if (!dp[i][j] || (i == n && j == n)) continue;

            long long val = arr[i][j];
            long long d = val + i;
            long long r = val + j;

            if (d <= n) dp[d][j] += dp[i][j];
            if (r <= n) dp[i][r] += dp[i][j];
        }
    }

    cout << dp[n][n];
    return 0;
}
