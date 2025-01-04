#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n;
	cin >> n;
	queue<long long>q;
	for (int i = 1; i <= n; i++)
		q.push(i);
	while (q.size() > 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}
