#include <iostream>
#include <stack>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	stack<int>s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			s.pop();
		}
		else s.push(tmp);
	}
	int ans = 0;
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans;
}
