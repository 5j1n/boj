#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ret;
string s, t;
void recur(string str) {
    if (s == str) {
        ret = 1;
        return;
    }
    else if (str.size() <= s.size()) return;
    if (str[0] == 'B') {
        string tmp = str;
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        recur(tmp);
    }
    if (str[str.size() - 1] == 'A') {
        str.pop_back();
        recur(str);
    }
}
int main() {
    cin >> s >> t;
    recur(t);
    cout << ret;
}
