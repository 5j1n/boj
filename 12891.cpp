#include <iostream>
using namespace std;

int n, m, a, c, g, t, ans, idx;
int arr[26];
string str;

int main() {
	cin >> n >> m;
	cin >> str;
	cin >> a >> c >> g >> t;

	for (int j = 0; j < m; j++) {
		arr[str[j] - 'A']++;
	}
	if (arr['A' - 'A'] >= a && arr['C' - 'A'] >= c && arr['G' - 'A'] >= g && arr['T' - 'A'] >= t)
		ans++;
	
	for (int i = m; i < n; i++) {
		arr[str[i - m] - 'A']--;
		arr[str[i] - 'A']++;
		if (arr['A' - 'A'] >= a && arr['C' - 'A'] >= c && arr['G' - 'A'] >= g && arr['T' - 'A'] >= t)
			ans++;
	}

	cout << ans;
}
