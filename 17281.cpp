#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, ans;
int arr[10], abil[51][10];   
bool visited[10]; 

void game() {
    int score = 0;
    int start = 1;

    for (int inning = 1; inning <= n; inning++) {
        int Base[4] = { 0 }; 
        int out = 0;

        while (out < 3) {
            for (int i = start; i < 10; ++i) {
                int result = abil[inning][arr[i]];

                if (result == 0) {
                    out++;
                }
                else {
                    for (int base = 3; base >= 1; --base) {
                        if (Base[base] == 1) {
                            if (base + result >= 4) {
                                score++;
                            }
                            else {
                                Base[base + result] = 1;
                            }
                            Base[base] = 0;
                        }
                    }

                    if (result == 4) {
                        score++;
                    }
                    else {
                        Base[result] = 1;
                    }
                }

                if (out == 3) {
                    start = i + 1;
                    if (start == 10) start = 1;
                    break;
                }
            }
            if (out == 3) break;
            start = 1;
        }
    }
    ans = max(ans, score);
}
void dfs(int count) {
    if (count == 10) {
        game();
        return;
    }

    for (int i = 1; i < 10; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        if (count == 4) count++;
        arr[count] = i;
        dfs(count + 1);
        visited[i] = false;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < 10; ++j) {
            cin >> abil[i][j];
        }
    }
    visited[1] = true;
    arr[4] = 1;
    dfs(1);
    cout << ans << endl;

    return 0;
}
