#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>>v;
priority_queue<int, vector<int>, greater<int>>q;

int main() {
	int n, ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int st, en;
		cin >> st >> en;
		v.push_back({ st,en });
	}
	sort(v.begin(), v.end());
	q.push(v[0].second);

	for (int i = 1; i < n; i++) {
		if (q.top() <= v[i].first) q.pop();
		q.push(v[i].second);
	}
	cout << q.size();
}
