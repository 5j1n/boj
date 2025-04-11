#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[9];
vector<int>candidate;
bool visited[9];
int n, ans;

void tracking(int cnt) {
	if (cnt == n) {
		int tmp = 0;
		for (int i = 1; i < n; i++) {
			tmp += abs(candidate[i] - candidate[i - 1]);
		}
		ans = max(ans, tmp);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			candidate.push_back(arr[i]);
			tracking(cnt + 1);
			visited[i] = 0;
			candidate.pop_back();
		}
	}
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	tracking(0);
	cout << ans;
}
