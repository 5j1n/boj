#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int visited[100001];
int cnt;
vector<int>arr;

void dfs(int cur) {
	visited[cur] = 1;
	int nxt = arr[cur];
	if (visited[nxt] == 0) {
		dfs(nxt);
	}
	else if (visited[nxt] == 1) {
		int pref_nxt = arr[nxt];
		while (1) {
			cnt++;
			if (nxt == pref_nxt) {
				break;
			}
			pref_nxt = arr[pref_nxt];
		}
	}
	visited[cur] = 2;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cnt = 0;
		int n;
		cin >> n;
		arr.resize(n + 1);
		memset(visited, 0, sizeof(visited));

		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		for (int i = 1; i <= n; i++)
			if (visited[i] == 0) dfs(i);

		cout << n - cnt << "\n";
	}
}
