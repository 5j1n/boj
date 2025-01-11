#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 200001; i++)
		arr[i] = 987654321;
	arr[n] = 0;
	queue<int>q;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int nx1 = cur - 1;
		int nx2 = cur + 1;
		int nx3 = 2 * cur;
		if (nx1 > -1 && arr[nx1] > arr[cur]+1) {
			arr[nx1] = arr[cur] + 1;
			q.push(nx1);
		}
		if (nx2 <= 200000 && arr[nx2] > arr[cur]+1) {
			arr[nx2] = arr[cur] + 1;
			q.push(nx2);
		}
		if (nx3 <= 200000 && arr[nx3] > arr[cur]) {
			arr[nx3] = arr[cur];
			q.push(nx3);
		}
	}
	cout << arr[m];
}
