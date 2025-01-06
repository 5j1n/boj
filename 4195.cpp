#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> p;
unordered_map<string, int> group_size;

string find_set(string x) {
    if (p[x] != x) p[x] = find_set(p[x]);
    return p[x];
}

void uni(string a, string b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        p[b] = a;
        group_size[a] += group_size[b]; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        p.clear();
        group_size.clear();
        cin >> n;

        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;
            if (p.count(a) == 0) {
                p[a] = a;
                group_size[a] = 1; 
            }
            if (p.count(b) == 0) {
                p[b] = b;
                group_size[b] = 1; 
            }

            uni(a, b);
            cout << group_size[find_set(a)] << "\n"; 
        }
    }
    return 0;
}
