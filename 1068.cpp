#include <iostream>
#include <vector>
using namespace std;

vector<int>v[51];
int n, toDel;
int visited[51];
int parent, root, ans;

void dfs(int x) {
	if (visited[x]) return;
	visited[x] = 1;
	bool leaf = true;
	for (int i = 0; i < v[x].size(); i++) {
		int nxt = v[x][i];
		if (!visited[nxt]) {
			dfs(nxt);
			leaf = false;
		}
	}
	if (leaf) ans++;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> parent;
		if (parent == -1) root = i;
		else v[parent].push_back(i);
	}
	cin >> toDel;
	visited[toDel] = true;
	dfs(root);
	cout << ans;
}
