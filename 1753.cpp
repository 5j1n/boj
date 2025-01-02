#include <iostream>
#include <vector>
#include <queue>

#define MAX 20010
#define INF 0xfffffff
using namespace std;

int v, e, start;
int d[MAX];
vector<pair<int, int>>adj[MAX];

void dij() {
	priority_queue<pair<int, int>>pq;
	pq.push(make_pair(0, start));
	d[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i].first;
			int ncost = adj[cur][i].second;

			if (d[nxt] > cost + ncost) {
				d[nxt] = cost + ncost;
				pq.push(make_pair(-d[nxt], nxt));
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> v >> e >> start;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	for (int i = 1; i <= v; i++)
		d[i] = INF;
	dij();
}
