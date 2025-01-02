#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool prime[2000001];

int main() {
    memset(prime, true, sizeof(prime));

    prime[1] = false;

    for (int i = 2; i <= 2000000; i++) {
        if (prime[i]) {
            int tmp = 2;
            while (i * tmp <= 2000000) {
                prime[i * tmp] = false;
                tmp++;
            }
        }
    }

    int n;
    cin >> n;

    for (int i = n;; i++) {
        if (prime[i]) {
            string str = to_string(i);
            bool ispalin = true;
            for (int j = 0; j < str.length(); j++) {
                if (str[j] != str[str.length() - j - 1]) { 
                    ispalin = false;
                    break;
                }
            }
            if (ispalin) {
                cout << str;
                return 0;
            }
        }
    }

    return 0;
}
