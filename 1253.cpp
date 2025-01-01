#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<int>v;
	int n, m, start, end, ans = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
	}

	if (n <= 2) {
		cout << 0;
		return 0;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		vector<int>tmp = v;
		tmp.erase(tmp.begin() + i);

		start = 0; end = n - 2;

		while (start < end) {
			int sum = tmp[start] + tmp[end];

			if (sum == v[i]) {
				ans++;
				break;
			}

			if (sum < v[i]) start++;
			else end--;
		}
	}

	cout << ans;

}
