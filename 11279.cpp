#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	priority_queue<int>q;
	while (n--) {
		int command;
		cin >> command;
		if (command == 0) {
			if (q.empty()) cout << "0\n";
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
			q.push(command);
	}
}
