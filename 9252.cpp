#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001];
int a, b, ans;
string str1, str2, ret;

int main() {
	cin >> str1 >> str2;
	a = str1.length(); b = str2.length();

	for (int i = 1; i<=a; i++)
		for (int j = 1; j <= b; j++)
		{
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}

			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

	int i = a, j = b;
	while (i >= 1 && j >= 1) {
		if (dp[i][j] > dp[i - 1][j] && dp[i - 1][j] == dp[i][j - 1] && dp[i][j - 1] == dp[i - 1][j - 1]) {
			ret += str2[j - 1];
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1] && dp[i - 1][j] == dp[i][j]) {
			i--;
		}
		else if (dp[i - 1][j] < dp[i][j - 1] && dp[i][j - 1] == dp[i][j]) {
			j--;
		}
		else {
			j--;
		}
	}

	reverse(ret.begin(), ret.end());
	if (!dp[a][b])
		cout << "0";
	else
		cout << dp[a][b] << "\n" << ret;
}
