#include <iostream>
#include <vector>
using namespace std;

int arr[101][101];
int n, l, ans;

bool canPlaceSlope(vector<int>& line) {
    vector<bool> placed(n, false);
    for (int i = 1; i < n; i++) {
        if (line[i] == line[i - 1]) continue;
        if (abs(line[i] - line[i - 1]) > 1) return false;

        if (line[i] > line[i - 1]) { 
            for (int j = i - 1; j >= i - l; j--) {
                if (j < 0 || line[j] != line[i - 1] || placed[j]) return false;
                placed[j] = true;
            }
        }
        else {
            for (int j = i; j < i + l; j++) {
                if (j >= n || line[j] != line[i] || placed[j]) return false;
                placed[j] = true;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> l;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        vector<int> row(n), col(n);
        for (int j = 0; j < n; j++) {
            row[j] = arr[i][j];
            col[j] = arr[j][i];
        }
        if (canPlaceSlope(row)) ans++;
        if (canPlaceSlope(col)) ans++;
    }

    cout << ans;
    return 0;
}
