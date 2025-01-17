#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[300001];
int n, m, k, x, cnt;
vector<int>v[300001];

void dij(int start) {
	visited[start] = 0;
	queue<int>q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i];
			if (visited[nxt] == -1) {
				visited[nxt] = visited[cur] + 1;
				q.push(nxt);
			}
		}
	}

}
int main() {
	cin >> n >> m >> k >> x;
	fill(visited, visited + n + 1, -1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	dij(x);

	for (int i = 1; i <= n; i++)
		if (visited[i] == k)
		{
			cout << i << "\n";
			cnt++;
		}

	if (cnt == 0) cout << -1;
}
