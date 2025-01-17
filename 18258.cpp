#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n;
	cin >> n;
	deque<long long>q;
	for (long long i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			long long tmp;
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
