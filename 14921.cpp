#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n, ans = 987654321;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < v.size(); i++) {
		int st = i+1, en = v.size() - 1;
		while (st <= en) {
			int mid = (st + en) / 2;
			if (v[mid] + v[i] < 0) st = mid + 1;
			else if (v[mid] + v[i] > 0) en = mid - 1;
			else {
				cout << "0";
				return 0;
			}
			if (v[mid] + v[i] < 0 && abs(ans)>abs(v[mid] + v[i])) {
				ans = v[mid] + v[i];
			}
			else if (v[mid] + v[i] > 0 && abs(ans) > abs(v[mid] + v[i])) {
				ans = v[mid] + v[i];
			}
		}
	}
	cout << ans;
}
