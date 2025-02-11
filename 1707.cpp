#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int visited[20001];
vector<int>vec[20001];
queue<pair<int,int>>q;

bool bfs(int n) {
	visited[n] = 0;
	while (!q.empty()) {
		int nxt = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (visited[nxt] == -1) {
			visited[nxt] = dist;
			for (int i = 0; i < vec[nxt].size(); i++) {
				q.push({ vec[nxt][i],dist + 1 });
			}
		}
		else if (visited[nxt]%2 != dist % 2) {
			return false;
		}
	}
	return true;
}
int main() {
	int t;
	bool flag = true;
	cin >> t;
	while (t--) {
        flag = true;
		memset(visited, -1, sizeof(visited));
		while (!q.empty())q.pop();
		for (int i = 0; i < 20001; i++)
			vec[i].clear();
		int v, e;
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		for (int i = 1; i <= v; i++) {
			if (visited[i] == -1) {
				for (int j = 0; j < vec[i].size(); j++) {
					q.push({ vec[i][j],1 });
				}
				bool tmp_flag = bfs(i);

				if (!tmp_flag) {
					flag = false;
					cout << "NO\n";
					break;
				}
			}
		}
		if (flag) cout << "YES\n";
	}
}
