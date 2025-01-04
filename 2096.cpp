#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[100001][3];
int maxi, mini;
int main() {
    int n;
    cin >> n;

    int prev_maxdp[3], prev_mindp[3];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
            if (i == 1) {
                prev_maxdp[j] = arr[i][j];
                prev_mindp[j] = arr[i][j];
            }
        }

        int maxdp[3], mindp[3];
        for (int j = 0; j < 3; j++) {
            maxdp[j] = prev_maxdp[j];
            mindp[j] = prev_mindp[j];
        }

        if (i == 1) continue;
        maxdp[0] = max(prev_maxdp[1], prev_maxdp[0]) + arr[i][0];
        maxdp[1] = max(prev_maxdp[1], max(prev_maxdp[0], prev_maxdp[2])) + arr[i][1];
        maxdp[2] = max(prev_maxdp[1], prev_maxdp[2]) + arr[i][2];

        mindp[0] = min(prev_mindp[1], prev_mindp[0]) + arr[i][0];
        mindp[1] = min(prev_mindp[1], min(prev_mindp[0], prev_mindp[2])) + arr[i][1];
        mindp[2] = min(prev_mindp[1], prev_mindp[2]) + arr[i][2];

        for (int j = 0; j < 3; j++) {
            prev_maxdp[j] = maxdp[j];
            prev_mindp[j] = mindp[j];
        }
    }

    maxi = max(prev_maxdp[0], max(prev_maxdp[1], prev_maxdp[2]));
    mini = min(prev_mindp[0], min(prev_mindp[1], prev_mindp[2]));

    cout << maxi << " " << mini;

    return 0;
}
