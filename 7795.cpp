#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, ans = 0;
		cin >> n >> m;
		vector<int>A(n), B(m);

		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 0; i < m; i++)
			cin >> B[i];

		sort(A.begin(), A.end());
		sort(B.begin(), B.end(), cmp);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (A[i] > B[j]) {
					ans += m - j;
					break;
				}
			}
		}
		cout << ans<<"\n";
	}
}
