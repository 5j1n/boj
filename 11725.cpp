#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int>v[100001];
int p[100001];

void bfs(int a) {
	queue<int>q;
	p[a] = a;
	q.push(a);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i];
			if (p[nxt] == 0) {
				q.push(nxt);
				p[nxt] = cur;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(1);
	for (int i = 2; i <= n; i++)
		cout << p[i] << "\n";
}
