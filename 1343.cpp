#include <iostream>
using namespace std;

string str, ans;

int clear(int a) {
    int tmp = a;
    while (tmp % 2 == 0&&tmp>0) {
        if (tmp >= 4) {
            ans.append("AAAA");
            tmp -= 4;
           
        }
        else if (tmp >= 2) {
            ans.append("BB");
            tmp -= 2;
        }
    }
    return tmp;
}

int main() {
    cin >> str;
    int tmp = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            if (clear(tmp)>0) {
                cout << -1;
                return 0;
            }
            tmp = 0;
            ans.append(".");
        }
        else {
            tmp++;
        }
    }

    if (clear(tmp) > 0) {
        cout << -1;
        return 0;
    }

    cout << ans;
    return 0;
}
