#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int visited[501];
vector<int>v[501];
int n, m;

int bfs(int start) {
	visited[start] = 0;
	queue<int>q;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto it = v[cur].begin(); it != v[cur].end(); it++) {
			if (visited[*it]==INT_MAX) {
				q.push(*it);
				visited[*it] = visited[cur] + 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 2; i <= n; i++)
	{
		if (visited[i] < 3) cnt++;
	}

	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		visited[i] = INT_MAX;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	cout << bfs(1);
}
