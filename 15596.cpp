#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int,int>>v[5001];
int visited[5001];

void bfs(int st) {
	visited[st] = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < v[st].size(); i++) {
		q.push({ v[st][i].first,v[st][i].second });
	}

	while (!q.empty()) {
		int nx = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (visited[nx] != -1) continue;

		visited[nx] = dist;
		for (int i = 0; i < v[nx].size(); i++) {
			if (visited[v[nx][i].first] > dist || visited[v[nx][i].first]==-1) {
				q.push({ v[nx][i].first, min(v[nx][i].second,dist) });
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		memset(visited, -1, sizeof(visited));
		bfs(b);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (visited[i] >= a)
			{
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}
