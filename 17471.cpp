#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

bool area[11], bfs_visited[11];
int population[11], n, ans = INT_MAX, tot = 0;
vector<int> v[11];

int bfs() {
	memset(bfs_visited, 0, sizeof(bfs_visited));
	int ret = population[1];
	queue<int>q;
	bfs_visited[1] = 1;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i];
			if (bfs_visited[nxt] || area[nxt] != area[cur]) continue;
			ret += population[nxt];
			bfs_visited[nxt] = 1;
			q.push(nxt);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!bfs_visited[i]) {
			bfs_visited[i] = 1;
			q.push(i);

			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (int i = 0; i < v[cur].size(); i++) {
					int nxt = v[cur][i];
					if (bfs_visited[nxt] || area[nxt] != area[cur]) continue;
					bfs_visited[nxt] = 1;
					q.push(nxt);
				}
			}
			break;
		}
	}
	for (int i = 1; i <= n; i++)
		if (!bfs_visited[i]) return INT_MAX;

	return abs(tot - 2 * ret);
}

void tracking(int idx) {
    if (idx > n) {
		int tmp = bfs();
		if (tmp < INT_MAX) {
			ans = min(ans, tmp);
		}
        return;
    }

    area[idx] = 0;
    tracking(idx + 1);

    area[idx] = 1;
    tracking(idx + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> population[i];
        tot += population[i];
    }

    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int to;
            cin >> to;
            v[i].push_back(to);
        }
    }

    tracking(1);

    if (ans == INT_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
}
