#include <iostream>
#include <cstring>
using namespace std;

int arr[6], visited[50], v[14];
int n;

void dfs(int start, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < cnt; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = start; i < n; i++) {
		arr[cnt] = v[i];
		dfs(i + 1, cnt + 1);
	}

}
int main() {
	while (1) {
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		memset(v, 1, sizeof(v));
		
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		dfs(0, 0);
		cout << "\n";
	}
}
