#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	deque<char>q;
	bool stop = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '<') {
			while (!q.empty()) {
				cout << q.back();
				q.pop_back();
			}
			stop = true;
			cout << '<';
		}
		else if (str[i] == '>') {
			while (!q.empty()) {
				cout << q.front();
				q.pop_front();
			}
			stop = false;
			cout << '>';
		}

		else if (str[i] == ' ') {
			if (stop) {
				while (!q.empty()) {
					cout << q.front();
					q.pop_front();
				}
			}
			else {
				while (!q.empty()) {
					cout << q.back();
					q.pop_back();
				}
			}
			cout << " ";
		}
		else {
			q.push_back(str[i]);
		}
	}

	if (stop) {
		while (!q.empty()) {
			cout << q.front();
			q.pop_front();
		}
	}
	else {
		while (!q.empty()) {
			cout << q.back();
			q.pop_back();
		}
	}
}
