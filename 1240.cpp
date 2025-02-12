#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>>v[1001];
bool visited[1001];

int bfs(int x, int y) {
	visited[x] = true;
	queue<pair<int, int>>q;
	for (int i = 0; i < v[x].size(); i++) {
		q.push({ v[x][i].first,v[x][i].second });
	}
	while (!q.empty()) {
		int nxt = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (visited[nxt]) continue;
		if (nxt == y) return dist;
		visited[nxt] = true;
		for (int i = 0; i < v[nxt].size(); i++) {
			q.push({ v[nxt][i].first,v[nxt][i].second + dist });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		v[a].push_back({ b,d });
		v[b].push_back({ a,d });
	}
	for (int i = 0; i < m; i++) {
		memset(visited, false, sizeof(visited));
		int a, b;
		cin >> a >> b;
		cout << bfs(a, b)<<"\n";
	}
}
