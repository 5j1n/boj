#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 0xffffff
using namespace std;

vector<pair<int,int>>v[1001];
int total[1001], visited[1001];
int n, m, x, ans;

void dij(int x) {
	visited[x] = 0;
	priority_queue <pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({ 0,x });
	while (!q.empty()) {
		int cur = q.top().second;
		int curw = q.top().first;
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i].second;
			int nxtw = curw + v[cur][i].first;
			if (visited[nxt] > nxtw) {
				visited[nxt] = nxtw;
				q.push({ nxtw,nxt });
			}
		}
	}
}
int main() {
	cin >> n >> m >> x;
	fill(visited, visited + n + 1, INF);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({ w,b });
	}

	dij(x);
	for (int i = 1; i <= n; i++) {
		if (i != x) {
			total[i] = visited[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i != x) {
			fill(visited, visited + n + 1, INF);
			dij(i);
			total[i] += visited[x];
			ans = max(ans, total[i]);
		}
	}
	cout << ans;
}
