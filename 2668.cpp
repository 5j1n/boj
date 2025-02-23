#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int v[101];
bool visited[101];
int ans;
set<int>Set;

void dfs(int st) {
	set<int>tmp_set;
	memset(visited, false, sizeof(visited));
	stack<int>s;
	s.push(st);

	while (!s.empty()) {
		int nx = s.top();
		s.pop();

		if (visited[nx]) { 
			if (nx == st) {
				for (auto it = tmp_set.begin(); it != tmp_set.end(); it++)
					Set.insert(*it);
				return;
			}
			continue; 
		}
		tmp_set.insert(nx);
		visited[nx] = true;
		s.push(v[nx]);
		
	}
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		v[i] = tmp;
	}

	for (int i = 1; i <= n; i++) {
		dfs(i);
	}

	cout << Set.size()<<"\n";
	for (auto it = Set.begin(); it != Set.end(); it++)
		cout << *it << "\n";
}
