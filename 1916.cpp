#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 0xfffffff
using namespace std;

vector<pair<int, int>>v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
vector<int>d(1001, INF);

void dij(int start) {
    d[start] = 0;
    q.push({ 0, start });
    while (!q.empty()) {
        int curW = q.top().first;
        int cur = q.top().second;
        q.pop();
        if (d[cur] < curW) continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int nxt = v[cur][i].second;
            int nxtW = v[cur][i].first;

            if (d[cur]+nxtW < d[nxt]) {
                d[nxt] = nxtW + d[cur];
                q.push({ d[nxt],nxt });
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, st, en;
    cin >> n >> m;
  //  fill(d, d + n + 1, INF);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({ w, b });
     //   v[b].push_back({ w, a });
    }
    cin >> st >> en;
    dij(st);
    cout << d[en];

    return 0;
}
