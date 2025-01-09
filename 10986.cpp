#include <iostream>
using namespace std;
using ll = long long;

ll arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	ll sum = 0, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		sum += a;
		arr[sum % m]++;
	}
	for (int i = 0; i <= m; i++)
		cnt += arr[i] * (arr[i] - 1) / 2;

	cnt += arr[0];
	cout << cnt;
}
