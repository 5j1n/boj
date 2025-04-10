#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Fish {
    int d;
    bool alive = true;
};

int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int Dx[] = {0, -1, 0, 1, 0}; // 1~4: ↑←↓→
int Dy[] = {0, 0, -1, 0, 1};

vector<Fish> arr[5][5], tmp[5][5], pre_arr[5][5];
vector<int> route, candidate;
int smell[5][5];
bool visited[5][5];
pair<int, int> shark;

void fish_move() {
    // tmp 초기화
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            tmp[i][j].clear();

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 0; k < arr[i][j].size(); k++) {
                Fish f = arr[i][j][k];
                bool moved = false;
                for (int rot = 0; rot < 8; rot++) {
                    int nd = f.d - rot;
                    if (nd <= 0) nd += 8;
                    int nx = i + dx[nd];
                    int ny = j + dy[nd];
                    if (nx < 1 || ny < 1 || nx > 4 || ny > 4) continue;
                    if (nx == shark.first && ny == shark.second) continue;
                    if (smell[nx][ny]) continue;
                    tmp[nx][ny].push_back({nd});
                    moved = true;
                    break;
                }
                if (!moved) tmp[i][j].push_back(f);
            }
        }
    }
}

void tracking(int size, int &max_eat) {
    if (size == 3) {
        int temp = 0;
        int x = shark.first;
        int y = shark.second;
        memset(visited, false, sizeof(visited));
        bool invalid = false;

        for (int i = 0; i < 3; i++) {
            int nx = x + Dx[route[i]];
            int ny = y + Dy[route[i]];
            if (nx < 1 || ny < 1 || nx > 4 || ny > 4) {
                invalid = true;
                break;
            }
            if (!visited[nx][ny]) {
                temp += tmp[nx][ny].size();
                visited[nx][ny] = true;
            }
            x = nx;
            y = ny;
        }

        if (invalid) return;

        int val = route[0] * 100 + route[1] * 10 + route[2];
        if (temp > max_eat) {
            max_eat = temp;
            candidate.clear();
            candidate.push_back(val);
        } else if (temp == max_eat) {
            candidate.push_back(val);
        }
        return;
    }

    for (int d = 1; d <= 4; d++) {
        route.push_back(d);
        tracking(size + 1, max_eat);
        route.pop_back();
    }
}

void shark_move(int t) {
    candidate.clear();
    int max_eat = -1;
    tracking(0, max_eat);
    sort(candidate.begin(), candidate.end());

    int x = shark.first;
    int y = shark.second;
    int dir_num = candidate[0];
    int to_div = 100;

    for (int i = 0; i < 3; i++) {
        int dir = dir_num / to_div;
        dir_num %= to_div;
        to_div /= 10;

        x += Dx[dir];
        y += Dy[dir];

        if (!tmp[x][y].empty()) {
            tmp[x][y].clear();
            smell[x][y] = t;
        }
    }
    shark.first = x;
    shark.second = y;
}

void smell_remove(int t) {
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if (t - smell[i][j] >= 2)
                smell[i][j] = 0;
}

void copy_fish() {
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++) {
            for (const auto& f : pre_arr[i][j])
                tmp[i][j].push_back(f);
        }

    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++) {
            arr[i][j] = tmp[i][j];
            tmp[i][j].clear();
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, s;
    cin >> m >> s;
    for (int i = 0; i < m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        arr[x][y].push_back({d});
    }
    cin >> shark.first >> shark.second;

    for (int S = 1; S <= s; S++) {
        // 1. 복제 준비
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++) {
                pre_arr[i][j].clear();
                for (const auto& f : arr[i][j])
                    pre_arr[i][j].push_back(f);
            }

        // 2. 물고기 이동
        fish_move();

        // 3. 상어 이동
        shark_move(S);

        // 4. 냄새 제거
        smell_remove(S);

        // 5. 복제 완료
        copy_fish();
    }

    int ans = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            ans += arr[i][j].size();

    cout << ans << "\n";
    return 0;
}
