#include <iostream>
using namespace std;

bool used1[35], used2[35], used3[35];

int n, cnt = 0;

void queen(int k) {
	if (k == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (used1[i] || used2[i+k] || used3[k-i+n-1]) continue;
		used1[i] = 1; used2[i+k] = 1; used3[k-i+n-1] = 1;
		queen(k + 1);
		used1[i] = 0; used2[i+k] = 0; used3[k-i+n-1] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	queen(0);
	cout << cnt;
}
