#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int>v[10001];
vector<int>ans;
int visited[10001];

int bfs(int a) {
	int val = 1;
	queue<int>q;
	q.push(a);
	visited[a] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i<v[cur].size(); i++)
			if (visited[v[cur][i]] == 0) {
				visited[v[cur][i]] = 1;
				q.push(v[cur][i]);
				val++;
			}
	}
	return val;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, maxi = -1;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		fill(visited, visited + 10001, 0);
		int tmp = bfs(i);
		if (tmp > maxi) {
			ans.clear();
			ans.push_back(i);
			maxi = tmp;
		}
		else if (tmp == maxi) {
			ans.push_back(i);
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}
