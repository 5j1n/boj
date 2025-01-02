#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>>q;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}
	while (q.size()>1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		q.push(a + b);
		ans += a + b;
	}

	cout << ans;
}
