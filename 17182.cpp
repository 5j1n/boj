#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int arr[11][11];
bool visited[11];
vector<int>v;
int n, k,ans=INT_MAX;

void tracking(int size) {
	if (size == n) {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += arr[v[i]][v[i + 1]];
		}
		ans = min(ans, sum);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			tracking(size + 1);
			v.pop_back();
			visited[i] = false;
    }
	}
}
int main() {
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[j][k] > arr[j][i] + arr[i][k]) {
					arr[j][k] = arr[j][i] + arr[i][k];
				}
			}
		}
	}
	v.push_back(k);
	visited[k] = true;
	tracking(1);
	cout << ans;
}
