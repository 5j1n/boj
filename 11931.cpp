#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int>q;
	int n;
	cin >> n;
	while (n--) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}

	while (!q.empty()) {
		cout << q.top() << "\n";
		q.pop();
	}
}
