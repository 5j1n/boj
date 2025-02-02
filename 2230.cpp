#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long  ans = 9876543210;

int main() {
	long long  n, m;
	cin >> n >> m;
	vector<long long >v(n);
	for (long long  i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	long long  st = 0, en = 0;

	while (en < n) {
		//cout << st << " " << en << "\n";
		if (st > en) en = st;
		if (v[en] - v[st] >= m) {
			ans = min(ans, (v[en] - v[st]));
			st++;
		}
		else en++;
		
	}
	cout << ans;
}
