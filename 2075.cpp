#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n, ret = 0;
	cin >> n;
	priority_queue<long long, vector<long long>, greater<long long>>q;
	for (long long i = 0; i < n * n; i++) {
		long long tmp;
		cin >> tmp;
		if (q.size() == n)
		{
			if (q.top() < tmp)
				q.pop();
			else
				continue;
		}
		q.push(tmp);
	}

	cout << q.top();
}
