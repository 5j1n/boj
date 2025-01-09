#include <iostream>
#include <vector>
using namespace std;

bool visited[9];
int n;
vector <int> v;

void dfs() {
    if (v.size() == n) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            v.push_back(i);
            dfs();
            visited[i] = false;
            v.pop_back();
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dfs();
}
