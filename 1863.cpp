#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	stack<int>s;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (s.empty() || s.top() < y) {
			if (y) s.push(y);
		}
		else if (s.top() > y) {
			while (!s.empty() && s.top() > y) {
				ans++;
				s.pop();
			}
			if (s.empty() || (!s.empty() && s.top() < y)) {
				if (y) s.push(y);
			}
		}
	}
	ans += s.size();

	cout << ans;

}
