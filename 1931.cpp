#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		pq.push(make_pair(end, start));
	}
	while (!pq.empty()) {
		ans++;
		int end = pq.top().first;
		//cout << end << " ";
		pq.pop();
		while (!pq.empty()&&end > pq.top().second)
			pq.pop();
	}
	cout << ans;


}
