#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr1[26], arr2[26], ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) {
		arr1[a[i] - 'a']++;
	}
	for (int i = 0; i < b.size(); i++) {
		arr2[b[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (arr1[i] != arr2[i])
			ans += abs(arr1[i] - arr2[i]);
	}
	cout << ans;
}
