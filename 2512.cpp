#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int>v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	cin >> m;
	int left = 0, right = v[n - 1];
	int ans, sum;

	while (left <= right) {
		sum = 0;
		int mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			sum += min(v[i], mid);
		}
		if (m >= sum) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid-1;
	}
	cout << ans;
}
