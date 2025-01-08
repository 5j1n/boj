#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int ans = 0;
	stack<char>s;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') s.push('(');
		else {
			if (str[i - 1] == '(') {
				s.pop();
				ans += s.size();
			}
			else {
				s.pop();
				ans++;
			}
		}
	}
	cout << ans;
}
