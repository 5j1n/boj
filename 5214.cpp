#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int n, k, m;
unordered_map<int, vector<int>> map;
int visited[200001];  

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;  

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : map[cur]) {
            if (visited[nxt] == 0) {  
                visited[nxt] = visited[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    cin >> n >> k >> m;

    vector<vector<int>> hyper_tubes(m);  

    for (int i = 0; i < m; i++) {
        hyper_tubes[i].resize(k);  
        for (int j = 0; j < k; j++) {
            cin >> hyper_tubes[i][j];
        }

        int hyper_node = n + i + 1; 
        for (int station : hyper_tubes[i]) {
            map[station].push_back(hyper_node);
            map[hyper_node].push_back(station);
        }
    }

    bfs(1);  

    if (visited[n] == 0) {
        cout << "-1\n";  
    }
    else {
        cout << visited[n] / 2 + 1 << "\n";  
    }

    return 0;
}
