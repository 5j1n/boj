#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int arr[21][21];
bool visited[21][21];
bool rainbow_visited[21][21];

int n, m, ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

pair<int, int> standard;

pair<pair<int, int>, pair<int, int>> bfs(int i, int j) {
    memset(visited, false, sizeof(visited));
    memset(rainbow_visited, false, sizeof(rainbow_visited));

    queue<pair<int, int>> q;
    vector<pair<int, int>> group;
    int color = arr[i][j];
    int cnt = 1, rainbow = 0;
    pair<int, int> std_block = { i, j };

    visited[i][j] = true;
    q.push({ i,j });
    group.push_back({ i,j });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;

            if (arr[nx][ny] == 0 && !rainbow_visited[nx][ny]) {
                rainbow_visited[nx][ny] = true;
                q.push({ nx, ny });
                group.push_back({ nx, ny });
                cnt++;
                rainbow++;
            }
            else if (arr[nx][ny] == color && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
                group.push_back({ nx, ny });
                cnt++;
                if (nx < std_block.first || (nx == std_block.first && ny < std_block.second)) {
                    std_block = { nx, ny };
                }
            }
        }
    }

    if (cnt < 2) return { {0, 0}, {0, 0} }; 
    return { {cnt, rainbow}, std_block };
}

int popping(int i, int j) {
    memset(visited, false, sizeof(visited));
    int color = arr[i][j];
    queue<pair<int, int>> q;
    q.push({ i,j });
    arr[i][j] = -2; 
    visited[i][j] = true;
    int cnt = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (visited[nx][ny]) continue;
            if (arr[nx][ny] == color || arr[nx][ny] == 0) {
                visited[nx][ny] = true;
                arr[nx][ny] = -2;
                q.push({ nx, ny });
                cnt++;
            }
        }
    }
    return cnt;
}

void drop() {
    for (int j = 1; j <= n; j++) {
        for (int i = n - 1; i >= 1; i--) {
            if (arr[i][j] >= 0) {
                int ni = i;
                while (ni + 1 <= n && arr[ni + 1][j] == -2) {
                    swap(arr[ni][j], arr[ni + 1][j]);
                    ni++;
                }
            }
        }
    }
}

void rotate() {
    int tmp[21][21];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            tmp[n - j + 1][i] = arr[i][j];
        }
    }
    memcpy(arr, tmp, sizeof(arr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    while (true) {
        int max_size = 0;
        int max_rainbow = 0;
        pair<int, int> max_pos = { 0, 0 };

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] > 0) {
                    auto result = bfs(i, j);
                    int size = result.first.first;
                    int rainbow = result.first.second;
                    pair<int, int> pos = result.second;

                    if (size > max_size ||
                        (size == max_size && rainbow > max_rainbow) ||
                        (size == max_size && rainbow == max_rainbow &&
                            (pos.first > max_pos.first ||
                                (pos.first == max_pos.first && pos.second > max_pos.second)))) {
                        max_size = size;
                        max_rainbow = rainbow;
                        max_pos = pos;
                    }
                }
            }
        }

        if (max_size < 2) break;

        int removed = popping(max_pos.first, max_pos.second);
        ans += removed * removed;

        drop();
        rotate();
        drop();
    }

    cout << ans << "\n";
    return 0;
}
