#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<pair<int, int>>v[50001];
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int dist[50001];

void bfs() {
	dist[1] = 0;
	while (!q.empty()) {
		int d = q.top().first;
		int nx = q.top().second;
		q.pop();

		if (dist[nx] == INT_MAX) {
			dist[nx] = d;
			for (int i = 0; i < v[nx].size(); i++) {
				q.push({ v[nx][i].second + d ,v[nx][i].first});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 2; i <= n; i++)
		dist[i] = INT_MAX;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		if (a == 1)
			q.push({ c,b });
		else if (b == 1)
			q.push({ c,a });
	}

	bfs();
	cout << dist[n];
}
