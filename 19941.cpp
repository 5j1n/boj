#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
string str;

int main() {
	cin >> n >> m;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'P') {
			for (int j = max(0, i - m); j <= min(n - 1, i + m); j++) {
				if (str[j] == 'H') {
					ans++;
					str[j] = 'N';
					break;
				}
			}
		}
	}
	cout << ans;

}
