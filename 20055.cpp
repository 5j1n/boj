#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> belt(2 * N);     
    vector<bool> robot(2 * N);  

    for (int i = 0; i < 2 * N; ++i) cin >> belt[i];

    int step = 0;
    while (true) {
        step++;
        int last = belt.back();
        for (int i = 2 * N - 1; i > 0; --i) {
            belt[i] = belt[i - 1];
            robot[i] = robot[i - 1];
        }
        belt[0] = last;
        robot[0] = false;
        robot[N - 1] = false;
        for (int i = N - 2; i >= 0; --i) {
            if (robot[i] && !robot[i + 1] && belt[i + 1] > 0) {
                robot[i] = false;
                robot[i + 1] = true;
                belt[i + 1]--;
            }
        }
        robot[N - 1] = false;

        if (belt[0] > 0 && !robot[0]) {
            robot[0] = true;
            belt[0]--;
        }

        int zero_count = 0;
        for (int i = 0; i < 2 * N; ++i)
            if (belt[i] == 0) zero_count++;

        if (zero_count >= K) break;
    }

    cout << step << "\n";
    return 0;
}
