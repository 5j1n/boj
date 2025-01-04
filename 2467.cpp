#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n, ans1, ans2, ans = INT_MAX;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int left = 0, right = n - 1;
    while (left < right) {
        if (abs(v[right] + v[left]) < abs(ans)) {
            ans = v[right] + v[left];
            ans1 = v[left];
            ans2 = v[right];
        }
        if (v[left] + v[right]== 0) {
            break;
        }
        else if (v[right] + v[left] > 0) right--;
        else left++;
    }
    cout << ans1 << " " << ans2;
}
