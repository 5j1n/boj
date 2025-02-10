#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long>pq[200001];

int main() {
	long long n,ans = 0;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		long long deadline, num;
		cin >> deadline >> num;
		pq[deadline].push(num);
	}
	priority_queue<long long>candidate;
	for (int day = n; day>0; day--){
		while (!pq[day].empty()) {
			candidate.push(pq[day].top());
			pq[day].pop();
		}
		if (candidate.empty()) continue;
		ans += candidate.top();
		candidate.pop();
	}
	cout << ans;
}
