#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long t;
	cin >> t;
	while (t--) {
		priority_queue<long long, vector<long long>, greater<long long>>pq;
		long long n, ans = 0;
		cin >> n;
		while (n--) {
			long long tmp;
			cin >> tmp;
			pq.push(tmp);
		}
		while (pq.size() >= 2) {
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();
			ans += a + b;
			pq.push(a + b);
		}
		cout << ans << "\n";
	}
}
