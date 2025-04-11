#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int visited[11];
int n, ans = INT_MAX;
int arr[11][11];
vector<int>v;

void tracking(int cnt) {
	if (cnt == n) {
		int tmp = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			if (!arr[v[i]][v[i + 1]]) {
				tmp = INT_MAX;
				break;
			}
			tmp += arr[v[i]][v[i + 1]];
		}
		if (tmp < INT_MAX) {
			if (!arr[v[v.size() - 1]][v[0]]) tmp = INT_MAX;
			else tmp += arr[v[v.size() - 1]][v[0]];
		}
		ans = min(tmp, ans);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			v.push_back(i);
			tracking(cnt + 1);
			visited[i] = 0;
			v.pop_back();
		}
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	tracking(0);
	cout << ans;
}
