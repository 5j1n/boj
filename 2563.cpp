#include <iostream>

using namespace std;

int arr[101][101];

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int i = a; i < a + 10; i++) {
			for (int j = b; j < b + 10; j++) {
				if (arr[i][j] == 0) {
					ans++;
					arr[i][j] = 1;
				}
			}
		}
	}
	cout << ans;
}
