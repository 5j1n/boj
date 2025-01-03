#include <iostream>
using namespace std;

int main() {
	int n, sum = 0, ans = 0;
	cin >> n;
	int left = 1, right = 1;
	while (left <= right && right <= n+1) {
		if (sum < n) {
			sum += right;
			right++;
			
		}
		else if (sum == n) {
			ans++;
			sum -= left;
			left++;
			
		}
		else {
			sum -= left;
			left++;
			
		}
	}
	cout << ans ;
}
