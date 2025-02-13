#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int praise[100001];
vector<int>v[100001];
unordered_map<int, int>praise_sum;
void bfs(int n, int num) {
	praise[n] += num;
	queue<int>q;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i];
			praise[nxt] += num;
			q.push(nxt);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int up;
		cin >> up;
		if (up != -1) v[up].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int st, num;
		cin >> st >> num;
		praise_sum[st] += num;
	}
	for (auto it = praise_sum.begin(); it != praise_sum.end(); it++) {
		int st = it->first;
		int num = it->second;
		bfs(st, num);
	}
	for (int i = 1; i <= n; i++)
		cout << praise[i] << " ";
}
