#include <iostream>
#include <deque>
using namespace std;

int n;
int main() {
	cin >> n;
	deque<pair<int, int>>dq;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		dq.push_back({ i,x });
	}

	while (!dq.empty()) {
		int a = dq.front().first;
		int b = dq.front().second;
		cout << a << " ";
		dq.pop_front();
		if (dq.empty()) {
			return 0;
		}
		if (b > 0) {
			b--;
			while (!b == 0) {
				dq.push_back(dq.front());
				dq.pop_front();
				b--;
			}
		}
		else {
			while (!b == 0) {
				dq.push_front(dq.back());
				dq.pop_back();
				b++;
			}
		}
	}

}
