#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, a, b, m, x, y;
vector<int>v[101];
vector<int>visited(101,-1);

void bfs(int a) {
	queue<pair<int, int>>q;
	visited[a] = 0;
	q.push({ a,visited[a] });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			if (visited[v[cur][i]] == -1) {
				visited[v[cur][i]] = cnt + 1;
				q.push({ v[cur][i],visited[v[cur][i]] });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> a >> b;
	cin >> m;

	

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(a);

	cout << visited[b];
}
