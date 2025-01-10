#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long,long long>>arr[1001];
vector<long long>ans;
long long visited[1001], pre[1001];
long long n, m;

void dij(long long start, long long end) {
	for (int i = 1; i <= n; i++)
		visited[i] = INT_MAX;
	visited[start] = 0;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>q;
	
	q.push({ 0,start });

	while (!q.empty()) {
		long long cur = q.top().second;
		long long dist = q.top().first;
		q.pop();
		if (visited[cur] < dist) continue;
		for (long long i = 0; i < arr[cur].size(); i++) {
			long long nxt = arr[cur][i].first;
			long long nxtdist = arr[cur][i].second;
		//	visited[nxt] = min(visited[nxt], nxtdist);
			if (visited[nxt] >nxtdist+dist) {
				pre[nxt] = cur;
				visited[nxt] = nxtdist+dist;
				q.push({ visited[nxt], nxt });
			}
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (long long i = 0; i < m; i++) {
		long long a, b, w;
		cin >> a >> b >> w;
		arr[a].push_back({ b,w });
	}

	long long start, end;
	cin >> start >> end;

	dij(start, end);

	cout << visited[end] << "\n";

	int idx = end;
	while (idx != 0) {
		ans.push_back(idx);
		idx = pre[idx];
	}

	cout << ans.size() << "\n";
	for (int i = ans.size()-1; i >=0; i--)
		cout << ans[i] << " ";

}
