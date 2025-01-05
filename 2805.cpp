#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, target, maxi = 0, ans = -1;
    cin >> n >> target;
    vector<long long> v(n);

    for (long long i = 0; i < n; i++) {
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }

    long long left = 0, right = maxi;

    while (left <= right) {
        long long sum = 0;
        long long mid = (left + right) / 2;

        for (long long i = 0; i < n; i++) {
            if (v[i] - mid > 0) sum += v[i] - mid;
         //   cout << v[i] - mid << "\n";
        }
       
        if (sum == target) {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else if (sum < target) {                                                     
            right = mid - 1;
        }
        else {
            ans = max(ans, mid);
            left = mid + 1;
        }
    }
    cout << ans;
}
