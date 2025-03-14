#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int arr[101][101];
unordered_map<int, int> count_map;
int r, c, k, row, col;
vector<pair<int, int>> v[101];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> arr[i][j];
        }
    }

    int t = 0;
    row = col = 3;

    while (t <= 100) {
        if (arr[r][c] == k) {
            cout << t;
            return 0;
        }

        if (row >= col) {
            int new_col = 0;
            for (int i = 1; i <= row; i++) {
                count_map.clear();
                for (int j = 1; j <= col; j++) {
                    if (arr[i][j] > 0) {
                        count_map[arr[i][j]]++;
                    }
                }
                v[i].clear();
                for (auto it : count_map) {
                    v[i].emplace_back(it.first, it.second);
                }
                sort(v[i].begin(), v[i].end(), cmp);
                new_col = max(new_col, (int)v[i].size() * 2);
            }

            col = min(new_col, 100);
            for (int i = 1; i <= row; i++) {
                int idx = 1;
                for (auto& p : v[i]) {
                    if (idx > 100) break;
                    arr[i][idx++] = p.first;
                    if (idx > 100) break;
                    arr[i][idx++] = p.second;
                }
                while (idx <= 100) arr[i][idx++] = 0;
            }
        }
        else { 
            int new_row = 0;
            for (int j = 1; j <= col; j++) {
                count_map.clear();
                for (int i = 1; i <= row; i++) {
                    if (arr[i][j] > 0) {
                        count_map[arr[i][j]]++;
                    }
                }
                v[j].clear();
                for (auto it : count_map) {
                    v[j].emplace_back(it.first, it.second);
                }
                sort(v[j].begin(), v[j].end(), cmp);
                new_row = max(new_row, (int)v[j].size() * 2);
            }

            row = min(new_row, 100);
            for (int j = 1; j <= col; j++) {
                int idx = 1;
                for (auto& p : v[j]) {
                    if (idx > 100) break;
                    arr[idx++][j] = p.first;
                    if (idx > 100) break;
                    arr[idx++][j] = p.second;
                }
                while (idx <= 100) arr[idx++][j] = 0;
            }
        }
        t++;
    }

    cout << -1;
    return 0;
}
