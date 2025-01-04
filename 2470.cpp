#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	long long n;
	pair<long long, long long>ans;
	cin >> n;
	vector<long long>v(n);

	for (long long i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	ans.first = v[0]; ans.second = v[n - 1];

	long long left = 0, right = n - 1;

	while (left < right) {
		if (abs(v[left] + v[right]) == 0) {
			ans.first = v[left];
			ans.second = v[right];
			break;
		}
		else if (abs(v[left] + v[right]) < abs(ans.first + ans.second)) {
			ans.first = v[left];
			ans.second = v[right];
		}
		if (v[left] + v[right] < 0) left++;
		else right--;
	}

	cout << ans.first << " " << ans.second;
}
