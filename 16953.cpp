#include <iostream>
#include <queue>
using namespace std;

long long a, b;
long long ans = -1;

void bfs() {
	queue<pair<long long, long long>>q;
	q.push({ a,1 });
	while (!q.empty()) {
		long long n = q.front().first;
		long long cnt = q.front().second;
		q.pop();
		if (n == b) {
			ans = cnt;
			return;
		}
		long long nn;
		nn = n * 2;
		if (nn <= b) {
			q.push({ nn,cnt + 1 });
		}
		nn = 10 * n + 1;
		if (nn <= b) {
			q.push({ nn,cnt + 1 });
		}
	}
}

int main() {
	cin >> a >> b;
	bfs();
	cout << ans;
}
