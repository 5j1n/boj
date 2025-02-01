#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long  n, ans;
long long  arr[4][4001];
vector<long long >AB, CD;
int main() {
	cin >> n;
	for (long long  i = 0; i < n; i++) {
		for (long long  j = 0; j < 4; j++) {
			cin >> arr[j][i];
		}
	}
	for (long long  i = 0; i < 4; i++) {
		sort(arr[i], arr[i] + n);
	}

	for (long long  i = 0; i < n; i++) {
		for (long long  j = 0; j < n; j++) {
			AB.push_back(arr[0][i] + arr[1][j]);
			CD.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	for (long long  i = 0; i < AB.size(); i++) {
		long long  idx1 = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
		long long  idx2 = upper_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
		ans += idx2 - idx1;
	}
	cout << ans;
}
