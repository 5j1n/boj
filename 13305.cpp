#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n, mini, ans = 0;
	cin >> n;
	vector<long long>d(n - 1), cost(n);
	for (long long i = 0; i < n - 1; i++)
		cin >> d[i];
	for (long long i = 0; i < n; i++)
		cin >> cost[i];
	mini = cost[0];
	for (long long i = 0; i < n - 1; i++) {
		if (mini > cost[i]) mini = cost[i];
		ans += mini * d[i];
	}
	cout << ans;
}
