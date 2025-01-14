#include <iostream>
using namespace std;

int arr[8];
bool visited[8];
int n, m;

void recur(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i] && arr[k-1] < i) {
			arr[k] = i;
			visited[i] = true;
			recur(k + 1);
			visited[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	recur(0);
}
