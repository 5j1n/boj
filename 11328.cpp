#include <iostream>
#include <cstring>
using namespace std;

int a[26], b[26];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; i++) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        string str;
        getline(cin, str); 

        int idx = 0;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == ' ') {
                idx = j + 1;
                break;
            }
            a[str[j] - 'a']++;
        }

        for (int j = idx; j < str.size(); j++) {
            b[str[j] - 'a']++;
        }

        bool isPossible = true;
        for (int j = 0; j < 26; j++) {
            if (a[j] != b[j]) {
                isPossible = false;
                break;
            }
        }

        if (isPossible) {
            cout << "Possible\n";
        }
        else {
            cout << "Impossible\n";
        }
    }

    return 0;
}
