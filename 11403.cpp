#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int>v[101];
int visited[101];

void dfs(int x) {
    for (int i = 0; i < v[x].size(); i++) {
        if (!visited[v[x][i]]) {
            visited[v[x][i]] = 1;
            dfs(v[x][i]);
        }
    }
}
int main() {
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a;
            if (a==1)v[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i);
        for (int j = 1; j <= n; j++)
            cout << visited[j] << " ";
        cout << "\n";
    }
}
