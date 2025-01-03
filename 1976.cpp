#include <iostream>
#include <vector>
using namespace std;

int p[201];

int find_set(int x) {
    if (p[x] != x) p[x] = find_set(p[x]);

    return p[x];
}

void uni(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a < b) p[b] = a;
    else p[a] = b;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp) uni(i, j);
        }
    }
   
    vector<int>v(m);
    for (int i = 0; i < m; i++)
        cin >> v[i];
    int parent = find_set(v[0]);
    bool possible = true;
    for (int i = 1; i < m; i++) {
        if (parent != find_set(v[i])) {
            possible = false;
            break;
        }
    }
    if (possible) cout << "YES";
    else cout << "NO";
}
