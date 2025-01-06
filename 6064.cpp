#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        
        int lcm_nm = lcm(n, m);
        bool possible = false;
        for (int i = 0; i < lcm_nm / n; i++) {
            int tmp = i * n + a;
            if ((tmp - 1) % m == (b - 1)) {
                possible = true;
                cout << tmp << endl;
                break;
            }
        }

        if (!possible)
            cout << -1 << endl;
    }
    return 0;
}
