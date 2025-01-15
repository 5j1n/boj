#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
vector<int> v;

int arr[9];

void tracking(int size) {
    if (size == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (arr[size - 1] <= v[i]) {
            arr[size] = v[i];
            tracking(size + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    set<int>set;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        set.insert(tmp);
    }
   
    for (auto i = set.begin(); i != set.end(); i++)
        v.push_back(*i);

    sort(v.begin(), v.end()); 
    tracking(0);

    return 0;
}
