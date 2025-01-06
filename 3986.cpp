#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		stack<char>s;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'A') {
				if (s.empty() || s.top() == 'B') s.push('A');
				else s.pop();
			}
			else if (str[i] == 'B') {
				if (s.empty() || s.top() == 'A') s.push('B');
				else s.pop();
			}

		}
		if (s.empty()) ans++;
	}
	cout << ans;

}
