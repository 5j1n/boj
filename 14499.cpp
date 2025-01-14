#include <iostream>
#include <vector>

using namespace std;

vector<int>dice(7);
int n, m, x, y, k;
int arr[21][21];
int command[1001];
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

void east()
{
    dice = { 0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3] };
}

void west()
{
    dice = { 0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4] };
}

void north()
{
    dice = { 0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2] };
}

void south()
{
    dice = { 0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5] };
}

int main() {
    cin >> n >> m >> y >> x >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> command[i];
    }

    for (int i = 0; i < k; i++) {
        int nx = x + dx[command[i]];
        int ny = y + dy[command[i]];

        if (nx >= m || ny >= n || nx < 0 || ny < 0) continue;
        x = nx;
        y = ny;


        if (command[i] == 1) east();
        else if (command[i] == 2) west();
        else if (command[i] == 3) north();
        else south();

        cout << dice[1] << "\n";

        if (arr[y][x] == 0)
            arr[y][x] = dice[6]; 
        else
        {
            dice[6] = arr[y][x];
            arr[y][x] = 0;
        }

    }
}
