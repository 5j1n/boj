#include <iostream>
#include <deque>

using namespace std;

int main() {
	int n;
	cin >> n;
	deque<int>q;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int tmp;
			cin >> tmp;
			q.push_back(tmp);
		}
		else if (str == "front") {
			if (!q.empty())
				cout << q.front()<<"\n";
			else cout << "-1\n";
		}
		else if (str == "back") {
			if (!q.empty())
				cout << q.back()<<"\n";
			else cout << "-1\n";
		}
		else if (str == "empty")
			cout << q.empty() << "\n";
		else if (str == "size")
			cout << q.size() << "\n";
		else if (str == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop_front();
			}
			else cout << "-1\n";
		}
	}
}
