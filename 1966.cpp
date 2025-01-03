#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, ans = 0;
		queue<pair<int, int>>q;
		priority_queue<int>pq;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			q.push({ i,x });
			pq.push(x);
		}
		while (!q.empty()){
			int curIdx = q.front().first;
			int curVal = q.front().second;
			q.pop();
			if (pq.top() == curVal) {
				pq.pop();
				ans++;
				if (curIdx == m) {
					cout << ans << "\n";
					break;
				}
			}
			else q.push({ curIdx,curVal });
		}
	}

}
