#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int>v, ans;
vector<int>arr;
int n;

bool is_prime(int n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}


void tracking(int num, int cnt) {
	if (cnt == n) {
		ans.push_back(num);
		return;
	}
	for (int i = 1; i < 10; i+=2) {
		int nxt = num * 10 + i;
		if (is_prime(nxt)) tracking(nxt, cnt + 1);
	}
}
int main() {
	cin >> n;
	tracking(2,1);
	tracking(3, 1);
	tracking(5, 1);
	tracking(7, 1);

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}
