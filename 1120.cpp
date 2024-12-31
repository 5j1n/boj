#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int ans = INT_MAX;
	for (int i = 0; i <= b.size() - a.size(); i++) {
		int tmp = 0;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != b[i + j]) tmp++;
		}
		ans = min(ans, tmp);
	}

	cout << ans;
}
