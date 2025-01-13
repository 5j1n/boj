#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int arr[1001], dp[1001];;

int main() {
	int n, ans = -1, ansidx;
	stack<int>s;
	fill(dp, dp + 1001, 1);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	for (int i = 0; i < n; i++)
	{
	//	cout << dp[i] << " ";
		ans = max(ans, dp[i]);
		ansidx = i;

	}
//	cout << "\n";
	int tmp = ans;
	for (int i = ansidx; i >= 0; i--) {
		if (dp[i] == tmp) {
			s.push(arr[i]);
			tmp--;
		}
	}
	cout << s.size()<<"\n";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}
