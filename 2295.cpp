#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>arr, two;

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp = arr[i] + arr[j];
			two.push_back(tmp);
		}
	}
	sort(arr.begin(), arr.end());
	sort(two.begin(), two.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp = arr[j] - arr[i];
			int st = 0, end = two.size() - 1;
			while (st <= end) {
				int mid = (st + end) / 2;
				if (two[mid] > tmp) end = mid - 1;
				else if (two[mid] < tmp) st = mid + 1;
				else {
					ans = max(ans, arr[j]);
					break;
				}
			}
		}
	}
	cout << ans;
}
