#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	deque<int>dq;
	int n;
	cin >> n;
	while (n--) {
		int command;
		cin >> command;
		if (command == 1) {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (command == 2) {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (command == 3) {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (command == 4) {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (command == 5)
			cout << dq.size() << "\n";
		else if (command == 6)
			cout << dq.empty() << "\n";
		else if (command == 7) {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << "\n";
			}
		}
		else if (command == 8) {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << "\n";
			}
		}
	}
}
