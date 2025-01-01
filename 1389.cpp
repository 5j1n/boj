#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>v[101];
int arr[101][101];

void bfs(int start) {
	int visited[101] = { 0, };
	queue<int>q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i];
			if (visited[nxt] == 0) {
				visited[nxt] = 1;
				q.push(nxt);
				arr[nxt][start] = arr[cur][start] + 1;
				arr[start][nxt] = arr[start][cur] + 1;
			}
		}
	}
}
int main() {
	int n, m, x, y, sum, result = 0, min = 0xfffffff;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	for (int i = 1; i <= n; i++)
		bfs(i);

	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += arr[i][j];
		}

		if (min > sum) {
			min = sum;
			result = i;
		}
	}
	cout << result;
}
