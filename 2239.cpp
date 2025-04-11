#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int board[9][9];
vector<pair<int, int>> blanks;

bool is_valid(int x, int y, int val) {
    for (int i = 0; i < 9; i++) {
        if (board[x][i] == val) return false;
        if (board[i][y] == val) return false;
    }

    int sx = (x / 3) * 3;
    int sy = (y / 3) * 3;
    for (int i = sx; i < sx + 3; i++) {
        for (int j = sy; j < sy + 3; j++) {
            if (board[i][j] == val) return false;
        }
    }
    return true;
}

bool solve(int idx) {
    if (idx == blanks.size()) return true;

    int x = blanks[idx].first;
    int y = blanks[idx].second;

    for (int num = 1; num <= 9; num++) {
        if (is_valid(x, y, num)) {
            board[x][y] = num;
            if (solve(idx + 1)) return true;
            board[x][y] = 0;
        }
    }

    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char tmp;
            cin >> tmp;
            board[i][j] = tmp - '0';
            if (board[i][j] == 0)
                blanks.emplace_back(i, j);
        }
    }

    solve(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}
