#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int n, k;

pair<int, int> v[300001];
int bag[300001];
priority_queue<int>pq;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	for (int i = 0; i < k; i++)
		cin >> bag[i];

	sort(v, v + n); sort(bag, bag + k);
	int idx = 0; ll sum = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && bag[i] >= v[idx].first) {
			pq.push(v[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;
}
