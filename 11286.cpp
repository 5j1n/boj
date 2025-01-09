#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	priority_queue<int>minus;
	priority_queue<int, vector<int>, greater<int>>plus;

	cin >> n;
	while (n--) {
		int command;
		cin >> command;
		if (command == 0) {
			if (plus.empty() && minus.empty())
				cout << 0 << "\n";
			else if (plus.empty()&&!minus.empty()) {
				cout << minus.top() << "\n";
				minus.pop();
			}
			else if (!plus.empty() && minus.empty()) {
				cout << plus.top() << "\n";
				plus.pop();
			}
			else {
				if (plus.top() >= -minus.top()) {
					cout << minus.top() << "\n";
					minus.pop();
				}
				else {
					cout << plus.top() << "\n";
					plus.pop();
				}
			}
		}
		else {
			if (command > 0) plus.push(command);
			else minus.push(command);
		}
	}
}
