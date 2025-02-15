#include <iostream>
#include <algorithm>

using namespace std;

int ans = 0, maxi = -1;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int arr[20];
		int num;
		cin >> num;
		for (int i = 0; i < 20; i++)
			cin >> arr[i];
		maxi = arr[0];
		for (int i = 1; i < 20; i++) {
			if (maxi < arr[i]) maxi = arr[i];
			else {
				int target_idx = 0;
				int val = arr[i];
				for (int j = 0; j < i; j++) {
					if (arr[j] > arr[i]) {
						target_idx = j;
						break;
					}

				}
				for (int j = i - 1; j >= target_idx; j--)
				{
					arr[j + 1] = arr[j];
					ans++;
				}
				arr[target_idx] = val;
			}

		}
		cout << num << " " << ans << "\n";
		ans = 0;
	}
}
