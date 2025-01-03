#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int left = 0, right = n - 1;
	while (left < right) {
		if (v[left] + v[right] == m) {
			ans++;
			left++;
			right--;
		}
		else if (v[left] + v[right] > m) {
			right--;
		}
		else left++;
	}
	cout << ans;
}
