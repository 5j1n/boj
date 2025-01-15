#include <iostream>
#include <queue>
using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	priority_queue<long long, vector<long long>, greater<long long>>q;
	for (long long i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		q.push(tmp);
	}

	while (m--) {
		long long a = q.top();
		q.pop();
		long long b = q.top();
		q.pop();
		q.push(a + b);
		q.push(a + b);
	}

	long long ans = 0;
	while (!q.empty()) {
		ans += q.top();
		q.pop();
	}

	cout << ans;
}
