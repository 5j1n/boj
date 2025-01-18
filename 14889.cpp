#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, ans = 9876543210;
int arr[21][21], visited[21], team1[10], team2[10];

void tracking(int size) {
	if (size == n / 2) {
		int idx = 0;
		for (int i = 1; i <= n; i++) {
			//cout << visited[i] << " ";
			if (visited[i] == 0) {
				team2[idx] = i;
				idx++;
			}
		}
		//cout << "\n";
		int tmp1 = 0, tmp2 = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = i+1; j < n / 2; j++) {
				tmp1 += arr[team1[i]][team1[j]];
				tmp1 += arr[team1[j]][team1[i]];
				tmp2 += arr[team2[i]][team2[j]];
				tmp2 += arr[team2[j]][team2[i]];
			}
		}
		ans = min(abs(tmp1 - tmp2), ans);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0&&team1[size-1]<i) {
			visited[i] = 1;
			team1[size] = i;
			tracking(size + 1);
			visited[i] = 0;
			team1[size] = 0;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}

	tracking(0);
	cout << ans;

}
