#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int ans = 0;
	vector<int>v;
	priority_queue<pair<int,int>>q;
	for (int i = 1; i <= 8; i++) {
		int tmp;
		cin >> tmp;
		q.push({ tmp,i });
	}

	for (int i = 0; i < 5; i++) {
		ans += q.top().first;
		v.push_back(q.top().second);
		q.pop();
	}

	sort(v.begin(), v.end());

	cout << ans << "\n";

	for (int i = 0; i < 5; i++)
		cout << v[i] << " ";
}
