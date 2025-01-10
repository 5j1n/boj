#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int>set;
    for (int i = 0; i < n + m; i++)
    {
        int tmp;
        cin >> tmp;
        set.insert(tmp);
    }

    for (auto it = set.begin(); it != set.end(); it++) {
        cout << *it<<" ";
   }
}
