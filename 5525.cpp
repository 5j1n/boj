#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, m, ans = 0;
	string key, str;
	cin >> n >> m;
	cin >> str;
	for (int i = 0; i < m; i++) {
		int k = 0;
		if (str[i] == 'O')
			continue;
		else {
			while (str[i + 1] == 'O' && str[i + 2] == 'I') {
				k++;
				if (k == n) {
					k--;
					ans++;
				}
				i += 2;
			}
			k = 0;
		}
	}

	cout << ans;
}
