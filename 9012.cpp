#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char>s;
		bool flag = false;
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') s.push('(');
			else {
				if (s.empty()) {
					flag = true;
				}
				else s.pop();
			}
		}
		if (flag || !s.empty()) cout << "NO\n";
		else cout << "YES\n";
	}
}
