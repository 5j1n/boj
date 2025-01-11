#include <iostream>
#include <queue>
#include <climits>
using namespace std;

pair<int, int> visited[200001]; 

void dfs(int n, int k) { 
    visited[n] = { 0, 1 }; 
    queue<pair<int, int>> q;
    q.push({ n, 0 });

    while (!q.empty()) {
        int cur = q.front().first;
        int curtime = q.front().second;
        q.pop();
        int nx1 = cur + 1;
        int nx2 = 2 * cur;
        int nx3 = cur - 1;

        if (nx1 <= 100000 && (visited[nx1].first == -1 || visited[nx1].first == curtime + 1)) {
            if (visited[nx1].first == -1) {
                visited[nx1].first = curtime + 1;
                q.push({ nx1, curtime + 1 });
            }
            visited[nx1].second += visited[cur].second;
        }

        if (nx2 <= 100000 && (visited[nx2].first == -1 || visited[nx2].first == curtime + 1)) {
            if (visited[nx2].first == -1) {
                visited[nx2].first = curtime + 1;
                q.push({ nx2, curtime + 1 });
            }
            visited[nx2].second += visited[cur].second;
        }

        if (nx3 >= 0 && (visited[nx3].first == -1 || visited[nx3].first == curtime + 1)) {
            if (visited[nx3].first == -1) {
                visited[nx3].first = curtime + 1;
                q.push({ nx3, curtime + 1 });
            }
            visited[nx3].second += visited[cur].second;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= 200000; i++)
        visited[i] = { -1, 0 };

    dfs(n, k);
    cout << visited[k].first << "\n" << visited[k].second;

    return 0;
}
