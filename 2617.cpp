#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int>in[100], out[100];
bool visited[100];
int n, e;

bool bfs(vector<int>v[], int a) {
	memset(visited, false, sizeof(visited));
	int ret = 0;
	visited[a] = true;
	queue<int>q;
	for (int i = 0; i < v[a].size(); i++) {
		q.push(v[a][i]);
	}
	while (!q.empty()) {
		int nxt = q.front();
		q.pop();
		if (visited[nxt])continue;
		visited[nxt] = true;
		ret++;
		for (int i = 0; i < v[nxt].size(); i++) {
			q.push(v[nxt][i]);
		}
 	}
	if (ret > n / 2) return true;
	else return false;

}
int main() {
	int ans = 0;
	
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		in[a].push_back(b);
		out[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (bfs(in,i)) ans++;
		if (bfs(out, i)) ans++;
	}
	cout << ans;
}
