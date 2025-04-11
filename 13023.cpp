#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;

vector<int> candidate;
unordered_set<int>v[2001];
int n, m;
bool visited[2001];

bool tracking(int cnt) {

	if (cnt == 5) {
		return true;
	}

	for (auto it = v[candidate[cnt - 1]].begin(); it != v[candidate[cnt - 1]].end(); it++) {
		if (!visited[*it]) {
			visited[*it] = true;
			candidate.push_back(*it);
			if (tracking(cnt + 1)) return true;
			visited[*it] = false;
			candidate.pop_back();
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].insert(b);
		v[b].insert(a);
	}
	bool flag = false;
	for (int i = 0; i < n; i++) {
		candidate.clear();
		candidate.push_back(i);
		memset(visited, false, sizeof(visited));
		visited[i] = 1;
		if (tracking(1)) {
			cout << 1;
			flag = true;
			break;
		};
	}
	if (!flag) cout << 0;

}

