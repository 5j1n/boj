#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

int arr[200002];
unordered_map<int, int> parent;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 초기화
    for (int i = 0; i < 200002; i++) 
        arr[i] = 987654321;

    int n, m;
    cin >> n >> m;

    queue<int> q;
    q.push(n);
    arr[n] = 0;
    parent[n] = -1; // 시작 노드의 부모 설정

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int nx1 = cur + 1;
        int nx2 = cur - 1;
        int nx3 = 2 * cur;

        if (nx1 < 200001 && arr[cur] + 1 < arr[nx1]) {
            arr[nx1] = arr[cur] + 1;
            q.push(nx1);
            parent[nx1] = cur; // 부모 저장
        }
        if (nx2 > -1 && arr[cur] + 1 < arr[nx2]) {
            arr[nx2] = arr[cur] + 1;
            q.push(nx2);
            parent[nx2] = cur; // 부모 저장
        }
        if (nx3 < 200001 && arr[cur] + 1 < arr[nx3]) {
            arr[nx3] = arr[cur] + 1;
            q.push(nx3);
            parent[nx3] = cur; // 부모 저장
        }
    }

    // 최단 거리 출력
    cout << arr[m] << "\n";

    // 경로 추적
    int now = m;
    stack<int>s;
    while (now != -1) {
        s.push(now);
        now = parent[now];
    }
    while (!s.empty()) {
        cout << s.top()<<" ";
        s.pop();
    }

}
