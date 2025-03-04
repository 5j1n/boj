#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, l, k, ans = 0;
    cin >> n >> m >> l >> k;

    vector<pair<int, int>> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int a = v[i].first;  
            int b = v[j].second;

            int cnt = 0;
            for (int o = 0; o < k; o++) {
                int x = v[o].first;
                int y = v[o].second;

                if (a <= x && x <= a + l && b <= y && y <= b + l) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }

    cout << k - ans;
}
