#include <iostream>
using namespace std;

int arr[2187][2187];
int cnt[3] = { 0, 0, 0 };

void recur(int x, int y, int size) {
    int firstValue = arr[x][y];
    bool isSame = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != firstValue) {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }

    if (isSame) {
        cnt[firstValue + 1]++;
        return;
    }

    int newSize = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            recur(x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    recur(0, 0, n);
    for (int i = 0; i < 3; i++)
        cout << cnt[i] << "\n";
    return 0;
}
