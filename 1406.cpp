#include <iostream>
#include <stack>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string str;
	stack<char>left, right;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		left.push(str[i]);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char command;
		cin >> command;
		if (command == 'P') {
			char tmp;
			cin >> tmp;
			left.push(tmp);
		}
		else if (command == 'L'&&!left.empty()) {
			right.push(left.top());
			left.pop();
		}
		else if (command == 'D' && !right.empty()) {
			left.push(right.top());
			right.pop();
		}
		else if (command == 'B' && !left.empty()) {
			left.pop();
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
}
