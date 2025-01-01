#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool visited[1001];
vector<int>v[1001];

void dfs(int start) {
	if (visited[start]) return;
	cout << start << " ";
	visited[start] = true;
	for (int i = 0; i < v[start].size(); i++) {
		if (!visited[v[start][i]]) dfs(v[start][i]);
	}
}

void bfs(int start) {
	
	visited[start] = true;
	queue<int>q;
	q.push(start);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << current << " ";
		for (int i = 0; i < v[current].size(); i++) {
			int nxt = v[current][i];
			if (visited[nxt]) continue;
			visited[nxt] = true;
			q.push(nxt);
		}
	}
}
int main() {
	int n, m, start;
	cin >> n >> m>>start;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	dfs(start);
	cout << "\n";
	fill(visited, visited + 1001, false);
	bfs(start);
}
