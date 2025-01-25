#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i<n; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i] > 0) {
			for (int j = 0; j < arr[i]; j++) {
				cout << i << "\n";
				cnt++;
			}
		}
		if (cnt == n) break;
	}
	
}
