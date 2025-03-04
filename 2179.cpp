#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> x, pair<int, string> y) {
    return x.second < y.second;
}

int checkPrefix(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] == b[i]) cnt++;
        else break;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, string>> b;
    for (int i = 0; i < n; i++) {
        b.push_back({ i, a[i] });
    }
    sort(b.begin(), b.end(), cmp);

    vector<int> length(n, 0);
    int maxlength = 0;

    for (int i = 0; i < n - 1; i++) {
        int tmp = checkPrefix(b[i].second, b[i + 1].second);
        maxlength = max(maxlength, tmp);

        int idx1 = b[i].first;
        int idx2 = b[i + 1].first;
        length[idx1] = max(length[idx1], tmp);
        length[idx2] = max(length[idx2], tmp);
    }

    string first = "", second = "";
    string prefix = "";

    for (int i = 0; i < n; i++) {
        if (first.empty() && length[i] == maxlength) {
            first = a[i];
            prefix = first.substr(0, maxlength);
            cout << first << "\n";
        }
        else if (!first.empty() && length[i] == maxlength && a[i].substr(0, maxlength) == prefix) {
            second = a[i];
            cout << second << "\n";
            break;
        }
    }

    return 0;
}
