#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int dp[10001];
vector<pair<pair<int, int>, int>>v;

bool cmp(pair<pair<int, int>, int>a, pair<pair<int, int>, int>b) {
	return a.first.first < b.first.first;
}
int main() {
	int n, dist;
	cin >> n >> dist;
	for (int i = 0; i <= dist; i++)
		dp[i] = i;
	for (int i = 0; i < n; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		if (b > dist) continue;
		v.push_back({ {a,b},d });
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		int  a = v[i].first.first;
		int b = v[i].first.second;
		int d = v[i].second;
		//cout << a << " " << b << " " << d << "\n";
		if (dp[b] > dp[a] + d) {
			dp[b] = dp[a] + d;
			for (int j = b + 1; j <= dist; j++) {
				if (dp[j] > dp[j - 1] + 1)
					dp[j] = dp[j - 1] + 1;
				else break;
			}
		}
	}
	cout << dp[dist];
}
