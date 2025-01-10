#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

using ll = long long;

void hanoi(int a, int b, int c, int n) {
    if (n == 1) {
        cout << a << " " << b << "\n";
        return;
    }
    hanoi(a, c, b, n - 1);
    cout << a << " " << b << "\n";
    hanoi(c, b, a, n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    ll ans = 1;
    for (int i = 0; i < n; i++)
        ans *= 2;
    cout << ans - 1 << "\n";

    hanoi(1, 3, 2, n);

    return 0;
}
