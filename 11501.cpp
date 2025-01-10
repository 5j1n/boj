#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long t;
	cin >> t;
	
	while (t--) {
		long long n, ans = 0, maxi = 0;
		cin >> n;
		vector<long long>arr(n);
		for (long long i = 0; i < n; i++)
			cin >> arr[i];

		maxi = arr[n - 1];
		for (long long i = arr.size() - 2; i >= 0; i--) {
			if (arr[i] > maxi) {
				maxi = arr[i];
			}
			else ans += maxi - arr[i];
		}
		cout << ans << "\n";
	}
}
