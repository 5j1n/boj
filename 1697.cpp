#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[200001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    arr[start] = 0; 

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur - 1 >= 0 && arr[cur - 1] == -1) {
            arr[cur - 1] = arr[cur] + 1;
            q.push(cur - 1);
        }

        if (cur + 1 < 200001 && arr[cur + 1] == -1) {
            arr[cur + 1] = arr[cur] + 1;
            q.push(cur + 1);
        }

        if (2 * cur < 200001 && arr[2 * cur] == -1) {
            arr[2 * cur] = arr[cur] + 1;
            q.push(2 * cur);
        }
    }
}

int main() {
    fill(arr, arr + 200001, -1);

    cin >> n >> m;
    bfs(n);

    cout << arr[m] << endl;
    return 0;
}
