#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m, ans = 0, pre;
	cin >> n >> m;
	vector<int>v;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	int st = 1;
	int en = v[n - 1] - v[0];
	pre = v[0];
	while (st <= en) {
		int mid = (st + en) / 2;
		int cnt = 1;
		pre = v[0];
		for (int i = 1; i < n; i++) {
			if (pre + mid <= v[i])
			{
				cnt++;
				pre = v[i];
			}
		}
		if (cnt >= m) {
			ans = max(ans, mid);
			st = mid + 1;
		}
		else en = mid - 1;
	}
	cout << ans;
}
