#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
bool visited[10001];
int main() {
	long long  n, ans = 0;
	cin >> n;
	vector<long long >v;
	for (long long  i = 0; i < n; i++) {
		long long  tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	for (long long  i = 0; i < n; i++) {
		for (long long  j = i + 1; j < n; j++) {
			long long sum = v[i] + v[j];
			int idx1 = lower_bound(v.begin() + j + 1, v.end(), -sum)-v.begin();
			int idx2 = upper_bound(v.begin() + j + 1, v.end(), -sum) - v.begin();
			ans += idx2 - idx1;
		}
	}
	cout << ans;
}
