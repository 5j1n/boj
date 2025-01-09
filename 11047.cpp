#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, target, ans = 0;
	cin >> n >> target;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = n - 1; i >= 0; i--) {
		if (target == 0) break;
		ans += target / v[i];
		target = target % v[i];
	}
	cout << ans;
}
