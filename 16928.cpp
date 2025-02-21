#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int arr[101], v[101];

int main() {
	int n, m;
	memset(arr, -1, sizeof(arr));
	arr[1] = 0;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int a, b;
		cin >> a >> b;
		v[a] = b;
	}
	queue<int>q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i < 7; i++) {
			int nx = cur + i;
			if (nx > 100) break;
			if (v[nx] > 0) {
				if (arr[nx] == -1) {
					arr[nx] = arr[cur] + 1;
					nx = v[nx];
				}
				
			}
			if (arr[nx] == -1) {
				arr[nx] = arr[cur] + 1;
				q.push(nx);
			}
		}
	}
	cout << arr[100];
}
