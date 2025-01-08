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
		string str;
		cin >> str;
		if (str == "push") {
			int tmp;
			cin >> tmp;
			s.push(tmp);
		}
		else if (str == "pop") {
			if (!s.empty()) {
				cout << s.top() << "\n";
				s.pop();
			}
			else cout << "-1\n";
		}
		else if (str == "size")
			cout << s.size() << "\n";
		else if (str == "empty") {
			cout << s.empty() << "\n";
		}
		else if (str == "top") {
			if (s.empty()) {
				cout << "-1\n";
			}
			else cout << s.top() << "\n";
		}
	}
}
