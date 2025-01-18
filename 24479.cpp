#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100001];
int n, m, r, cnt, visited[100001];

void dfs(int start) {
    if (visited[start] > 0) return;
    cnt++;
    visited[start] = cnt;
    for (int i = 0; i < v[start].size(); i++) {
        dfs(v[start][i]);
    }
}

int main() {
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    dfs(r);

    for (int i = 1; i <= n; i++)
        cout << visited[i] << "\n";
    return 0;
}
