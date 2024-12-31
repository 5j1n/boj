#include <iostream>
using namespace std;

long long fibo[50] = { 0,1, };
long long fibonacci(long long n) {
    if (n == 0 || n == 1) return fibo[n];
    else if (fibo[n] == 0) fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fibo[n];
}
int main() {
    long long t;
    cin >> t;
    long long tmp;
    for (long long i = 0; i < t; i++) {
        cin >> tmp;
        if (tmp == 0)
            cout << "1 0\n";
        else
            cout << fibonacci(tmp - 1) << " " << fibonacci(tmp) << "\n";
    }
}
