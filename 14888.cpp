#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

long long n, arr[12], visited[12];
vector<long long> sign, tmp_sign;
long long maxi = -1234567890, mini = 1234567890;

long long calculate(long long n, long long arr[], vector<long long> tmp_sign) {
    stack<long long> s;
    s.push(arr[0]);

    for (long long i = 0; i < tmp_sign.size(); i++) {
        long long a = s.top();
        s.pop();
        long long b = arr[i + 1];
        if (tmp_sign[i] == 0) s.push(a + b);
        else if (tmp_sign[i] == 1) s.push(a - b);
        else if (tmp_sign[i] == 2) s.push(a * b);
        else if (tmp_sign[i] == 3) s.push(a / b);
    }
    return s.top();
}

void tracking(long long size) {
    if (size == n - 1) {
        long long result = calculate(n, arr, tmp_sign);
        maxi = max(maxi, result);
        mini = min(mini, result);
        return;
    }

    for (long long i = 0; i < sign.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            tmp_sign.push_back(sign[i]);
            tracking(size + 1);
            tmp_sign.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    for (long long i = 0; i < 4; i++) {
        long long count;
        cin >> count;
        for (long long j = 0; j < count; j++) sign.push_back(i);
    }

    tracking(0);

    cout  << maxi << "\n";
    cout  << mini << "\n";

    return 0;
}
