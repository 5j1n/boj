#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark {
    int x, y, dir;
    bool alive = true;
};

int n, m, k, t;
int arr[21][21];
Shark sharks[401];
pair<int, int> smell[21][21]; // 상어 번호, 남은 시간
vector<int> priority[401][5]; // 상어 번호, 방향별 우선순위

int dx[5] = {0, -1, 1, 0, 0}; // 1: 상, 2: 하, 3: 좌, 4: 우
int dy[5] = {0, 0, 0, -1, 1};

bool inRange(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

void spread_smell() {
    for (int i = 1; i <= m; i++) {
        if (!sharks[i].alive) continue;
        smell[sharks[i].x][sharks[i].y] = {i, k};
    }
}

void decrease_smell() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (smell[i][j].second > 0) {
                smell[i][j].second--;
                if (smell[i][j].second == 0) smell[i][j].first = 0;
            }
        }
    }
}

void move_sharks() {
    int temp[21][21] = {0};
    for (int i = 1; i <= m; i++) {
        if (!sharks[i].alive) continue;

        int x = sharks[i].x;
        int y = sharks[i].y;
        int d = sharks[i].dir;
        bool moved = false;

        // 냄새 없는 곳 찾기
        for (int dir : priority[i][d]) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!inRange(nx, ny)) continue;
            if (smell[nx][ny].first == 0) {
                if (temp[nx][ny] == 0 || temp[nx][ny] > i) {
                    temp[nx][ny] = i;
                }
                sharks[i].x = nx;
                sharks[i].y = ny;
                sharks[i].dir = dir;
                moved = true;
                break;
            }
        }

        if (!moved) {
            // 자신의 냄새가 있는 칸 찾기
            for (int dir : priority[i][d]) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (!inRange(nx, ny)) continue;
                if (smell[nx][ny].first == i) {
                    sharks[i].x = nx;
                    sharks[i].y = ny;
                    sharks[i].dir = dir;
                    break;
                }
            }
        }
    }

    // 같은 칸에 작은 번호 상어만 생존
    for (int i = 1; i <= m; i++) {
        if (!sharks[i].alive) continue;
        int x = sharks[i].x;
        int y = sharks[i].y;
        for (int j = 1; j < i; j++) {
            if (sharks[j].alive && sharks[j].x == x && sharks[j].y == y) {
                sharks[i].alive = false;
                break;
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) {
                sharks[arr[i][j]] = {i, j, 0, true};
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int d; cin >> d;
        sharks[i].dir = d;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 0; k < 4; k++) {
                int d; cin >> d;
                priority[i][j].push_back(d);
            }
        }
    }

    t = 0;
    while (t <= 1000) {
        int alive_count = 0;
        for (int i = 2; i <= m; i++) {
            if (sharks[i].alive) alive_count++;
        }
        if (alive_count == 0) break;

        spread_smell();
        move_sharks();
        decrease_smell();
        t++;
    }

    if (t > 1000) cout << -1 << '\n';
    else cout << t << '\n';

    return 0;
}
