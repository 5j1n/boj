#include <iostream>
#include <cstring>
#define MAX 987654321
using namespace std;

int d[1000001], arr[1000001];
int n;

int main(void) {
    cin >> n;
    fill(d, d + n + 1, MAX);
    d[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (i + 1 <= n && d[i + 1] > d[i] + 1) {
            d[i + 1] = d[i] + 1;
            arr[i + 1] = i;
        }

        if (i * 2 <= n && d[i * 2] > d[i] + 1) {
            d[i * 2] = d[i] + 1;
            arr[i * 2] = i;
        }

        if (i * 3 <= n && d[i * 3] > d[i] + 1) {
            d[i * 3] = d[i] + 1;
            arr[i * 3] = i;
        }
    }

    cout << d[n] << '\n';

    while (1) {
        cout << n << ' ';
        n = arr[n];
        if (!n) break;
    }
}
