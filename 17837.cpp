#include <iostream>
#include <deque>

using namespace std;

int arr[15][15]; 
pair<int, int> loc[11];
deque<pair<int, int>> horse[15][15]; 
int n, k;
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

int main() {
    cin >> n >> k;

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            arr[i][j] = 2;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        horse[a][b].push_back({ i, c });
        loc[i] = { a, b };
    }

    int turn = 1;
    while (turn <= 1000) {
        for (int i = 1; i <= k; i++) {
            int x = loc[i].first;
            int y = loc[i].second;
            int idx = 0;
            bool found = false;
            deque<pair<int, int>> tmp_dq;

            for (int j = 0; j < horse[x][y].size(); j++) {
                if (horse[x][y][j].first == i) {
                    idx = j;
                    found = true;
                }
                if (found) tmp_dq.push_back(horse[x][y][j]);
            }

            horse[x][y].erase(horse[x][y].begin() + idx, horse[x][y].end());

            int dir = tmp_dq.front().second;
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            bool stopped = false;
            if ((nx < 1 || ny < 1 || nx > n || ny > n) || arr[nx][ny] == 2) {
                // 방향 반대로 변경
                if (dir == 1) dir = 2;
                else if (dir == 2) dir = 1;
                else if (dir == 3) dir = 4;
                else if (dir == 4) dir = 3;

                tmp_dq.front().second = dir;

                nx = x + dx[dir];
                ny = y + dy[dir];

                if ((nx < 1 || ny < 1 || nx > n || ny > n) || arr[nx][ny] == 2) {
                    nx = x;
                    ny = y;
                    stopped = true;
                }
            }

            if (!stopped) {
                if (arr[nx][ny] == 0) { 
                    for (auto h : tmp_dq) {
                        horse[nx][ny].push_back(h);
                        loc[h.first] = { nx, ny };
                    }
                }
                else if (arr[nx][ny] == 1) { 
                    for (int j = tmp_dq.size() - 1; j >= 0; j--) {
                        horse[nx][ny].push_back(tmp_dq[j]);
                        loc[tmp_dq[j].first] = { nx, ny };
                    }
                }
            }
            else {
                for (auto h : tmp_dq) {
                    horse[x][y].push_back(h);  
                    loc[h.first] = { x, y };
                }
            }

            if (horse[nx][ny].size() >= 4) {
                cout << turn;
                return 0;
            }
        }
        turn++;
    }

    cout << -1;
    return 0;
}
