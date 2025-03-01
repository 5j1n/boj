#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string current, target;

void toggle(vector<int>& bulbs, int idx) {
    if (!idx) {
        bulbs[0] = 1 - bulbs[0];
        bulbs[1] = 1 - bulbs[1];
    }
    else if (idx == N - 1) {
        bulbs[N-1] = 1 - bulbs[N-1];
        bulbs[N-2] = 1 - bulbs[N-2];
    }
    else {
        for (int i = idx - 1; i <= idx + 1 && i < N; i++) {
            bulbs[i] = 1 - bulbs[i];
        }
    }
}

int solve(bool firstSwitch) {
    vector<int> bulbs(N);
    for (int i = 0; i < N; i++) bulbs[i] = current[i] - '0'; 

    int count = 0;
    if (firstSwitch) {  
        toggle(bulbs, 0);
        count++;
    }

    for (int i = 1; i < N; i++) {
        if (bulbs[i - 1] != target[i - 1] - '0') {
            toggle(bulbs, i);
            count++;
        }
    }

    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (bulbs[i] + '0' != target[i]) {
            flag = true;
            break;
        }
    }
    if (flag) return -1;
    else return count;
}

int main() {
    cin >> N >> current >> target;

    int result1 = solve(false); 
    int result2 = solve(true);  

    if (result1 == -1 && result2 == -1) cout << -1;
    else if (result1 == -1) cout << result2;
    else if (result2 == -1) cout << result1;
    else cout << min(result1, result2);

    return 0;
}
