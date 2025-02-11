#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>>v[20001];
queue<pair<int, int>>q;
bool visited[20001];

pair<int,vector<int>> bfs() {
	int tmp = 0;
	vector<int>ret;
	visited[1] = true;
	while (!q.empty()) {
		int nxt = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (visited[nxt]) continue;
		visited[nxt] = true;

		if (dist > tmp) {
			ret.clear();
			ret.push_back(nxt);
			tmp = dist;
		}
		else if (dist == tmp) ret.push_back(nxt);

		for (int i = 0; i < v[nxt].size(); i++) {
			q.push({ v[nxt][i].first,dist + 1 });
		}
	}
	
	return { tmp,ret };
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back({b,1});
		v[b].push_back({a,1});
		if (a == 1) q.push({ b,1 });
		else if (b == 1)q.push({ a,1 });
	}
	pair<int, vector<int>>ans;
	ans = bfs();
	sort(ans.second.begin(), ans.second.end());
	cout << ans.second[0] << " " << ans.first << " " << ans.second.size();
}
