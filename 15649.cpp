#include <iostream>

using namespace std;

int n, m;
int arr[9];
bool used[9];

void back_tracking(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << "\n";
	}

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			used[i] = true;
			arr[k] = i;
			back_tracking(k + 1);
			used[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	back_tracking(0);
}
