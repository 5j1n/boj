#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>v[32001];
int d[32001], n, m;

void Sort() {
	queue<int>q;

	for (int i = 1; i <= n; i++) {
		if (!d[i])
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < v[cur].size(); i++) {
			d[v[cur][i]]--;
			if (!d[v[cur][i]])
				q.push(v[cur][i]);
		}
	}
		
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		d[b]++;
	}

	Sort();
}
