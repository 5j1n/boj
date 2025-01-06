#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int f, s, g, u, d;
int arr[2000001];
queue<int>q;

void bfs() {
	arr[s] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int nx1 = cur + u;
		int nx2 = cur - d;
		if (nx1 <= f && arr[nx1]==987654321) {
			arr[nx1] = arr[cur] + 1;
			q.push(nx1);
		}
		if (nx2 > 0 && arr[nx2] == 987654321) {
			arr[nx2] = arr[cur] + 1;
			q.push(nx2);
		}

		if (arr[g] < 987654321) break;
		
	}
}
int main() {
	cin >> f >> s >> g >> u >> d;
	for (int i = 0; i <=f; i++)
		arr[i] = 987654321;
	q.push(s);
	bfs();
	if (arr[g] < 987654321) cout << arr[g];
	else cout << "use the stairs";
}
