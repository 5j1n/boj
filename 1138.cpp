#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>v(n), ans(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++) {
		int tmp = 0;
		while (v[i] != 0) {
			if (!ans[tmp]) v[i]--;
			tmp++;
		}

		while (ans[tmp]) tmp++;
		ans[tmp] = i + 1;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}
