#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack<int>s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int command;
		cin >> command;
		if (command == 1) {
			int val;
			cin >> val;
			s.push(val);
		}
		else if (command == 2) {
			if (s.empty()) cout << "-1\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (command == 3) cout << s.size() << "\n";
		else if (command == 4) {
			if (s.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else {
			if (s.empty()) cout << "-1\n";
			else {
				cout << s.top() << "\n";
			}
		}
	}
}
