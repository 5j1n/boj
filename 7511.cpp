#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int t;
int parent[1000001];
vector<int>ans;
int find(int x) {
	if (parent[x] != x) parent[x] = find(parent[x]);
	return parent[x];
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;

	for (int i = 1; i <= t; i++) {
		memset(parent, -1, sizeof(parent));
		ans.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			parent[i] = i;
		int relate;
		cin >> relate;
		for (int i = 0; i < relate; i++) {
			int a, b;
			cin >> a >> b;
			uni(a, b);
		}

		int test;
		cin >> test;	
		
		for (int i = 0; i < test; i++) {
			int a, b;
			cin >> a >> b;
			if (find(a) == find(b)) ans.push_back(1);
			else ans.push_back(0);
		}

		cout << "Scenario " << i << ":\n";
		for (int i = 0; i < test; i++)
			cout << ans[i] << "\n";
		cout << "\n";
	}
}
