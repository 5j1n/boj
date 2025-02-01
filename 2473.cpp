#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long n, ans = 9876543210;
vector<long long> v, ret;

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for (long long i = 0; i < n - 2; i++) {
        long long left = i + 1, right = n - 1;
        while (left < right) {
            long long sum = v[i] + v[left] + v[right];

            if (abs(sum) < abs(ans)) {
                ans = sum;
                ret = { v[i], v[left], v[right] };
            }

            if (sum < 0) left++;
            else if (sum > 0) right--;
            else {
                ret = { v[i], v[left], v[right] };
                sort(ret.begin(), ret.end());
                for (int i = 0; i < 3; i++)
                    cout << ret[i] << " ";
                return 0;
            }
        }
    }

    sort(ret.begin(), ret.end());
    for (int i = 0; i < 3; i++)
        cout << ret[i] << " ";
    return 0;
}
