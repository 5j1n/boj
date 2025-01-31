#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long  m, n;
vector<long long >v;
bool solve(long long  x) {
    if (x == 0) return true;
    long long  cnt = 0;
    for (long long  i = 0; i < n; ++i) {
        cnt += (v[i] / x);
    }
    if (cnt >= m) return true;
    else return false;
}
int  main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (long long  i = 0; i < n; i++) {
        long long  tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    long long  st = 0;
    long long  end = v[n - 1];

    while (st < end) {
        long long  mid = (st + end + 1) / 2;
        if (solve(mid))
            st = mid;
        else
            end = mid - 1;
    }
    cout << st;
}
