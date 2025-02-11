#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, int>>v[51];
queue < pair<int, int>>q;
set<int>candidate;
bool visited[51];

int bfs(int cur) {
	int ret = 0;
	visited[cur] = true;
	while (!q.empty()) {
		int nxt = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (visited[nxt]) continue;
		ret = max(ret, dist);
		visited[nxt] = true;
		for (int i = 0; i < v[nxt].size(); i++) {
			q.push({ v[nxt][i].first, dist + 1 });
		}
	}
	return ret;
}
int main() {
	int n, mini = 9876543210;
	cin >> n;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		v[a].push_back({ b,1 });
		v[b].push_back({ a,1 });
	}

	for (int i = 1; i <= n; i++) {
		while (!q.empty()) q.pop();
		memset(visited, false, sizeof(visited));
		for (int j = 0; j < v[i].size(); j++) {
			q.push({ v[i][j].first,1 });
		}
		int tmp = bfs(i);
		if (tmp < mini) {
			candidate.clear();
			candidate.insert(i);
			mini = tmp;
		}
		else if (tmp == mini) candidate.insert(i);
	}
	cout << mini << " " << candidate.size() << "\n";
	for (auto it = candidate.begin(); it != candidate.end(); it++) {
		cout << *it << " ";
	}
}
