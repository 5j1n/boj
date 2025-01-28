#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, minus_num = 0, ans = 0, idx = 9876543210;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] < 0) minus_num++;
	}
	sort(v.begin(), v.end());
	
	if (minus_num % 2 == 0) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] < 0) {
				ans += v[i] * v[i + 1];
				i++;
			}
			else if (v[i] == 0 || v[i] == 1) {
				ans += v[i];
			}
			else {
				idx = i;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] < 0) {
				if (i < v.size() - 1 && v[i+1]<=0) {
					ans += v[i] * v[i + 1];
					i++;
				}
				else ans += v[i];
			}
			else if (v[i] == 0 || v[i] == 1) {
				ans += v[i];
			}
			else {
				idx = i;
				break;
			}
		}
	}
	for (int i = v.size() - 1; i >= idx; i--) {
		if (i == idx) ans += v[i];
		else {
			ans += v[i] * v[i - 1];
			i--;
		}
	}
	cout << ans;
}
