#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<string> results;

int evaluate(string str) {
    string tmp = "";

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') tmp += str[i];
    }

    int result = 0, num = 0;
    char sign = '+';

    for (int i = 0; i < tmp.size(); ++i) {
        char ch = tmp[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }

        if (!isdigit(ch) || i == tmp.size() - 1) {
            if (sign == '+') result += num;
            else if (sign == '-') result -= num;

            sign = ch;
            num = 0;
        }
    }
    return result;
}

void dfs(int idx, int n, string str) {
    if (idx > n) {
        if (evaluate(str) == 0) {
            results.push_back(str);
        }
        return;
    }

    string num = to_string(idx);
    dfs(idx + 1, n, str + "+" + num);
    dfs(idx + 1, n, str + "-" + num);
    dfs(idx + 1, n, str + " " + num);
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        results.clear();
        dfs(2, n, "1");
        sort(results.begin(), results.end());

        for (int i = 0; i < results.size(); i++) {
            cout << results[i] << "\n";
        }
        cout << "\n";
    }

    return 0;
}
