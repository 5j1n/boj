#include <iostream>
#include <stack>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		stack<char>left, right;

		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '<') {
				if (!left.empty()) {
					right.push(left.top());
					left.pop();
				}
			}
			else if (str[i] == '>') {
				if (!right.empty()) {
					left.push(right.top());
					right.pop();
				}
			}
			else if (str[i] == '-') {
				if (!left.empty()) {
					left.pop();
				}
			}
			else left.push(str[i]);
		}
		while (!left.empty()) {
			right.push(left.top());
			left.pop();
		}
		while (!right.empty()) {
			cout << right.top();
			right.pop();
		}
		cout << "\n";

	}
}
