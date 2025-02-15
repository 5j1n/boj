#include <iostream>

using namespace std;

long long h, w, n, m, ans;

int main() {
	cin >> h >> w >> n >> m;
	ans = ((h + n) / (n + 1)) * ((w + m) / (m + 1));
	cout << ans;
}

