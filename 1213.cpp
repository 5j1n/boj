#include <iostream>
using namespace std;

string str, ans;
int arr[26];

int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		arr[str[i] - 'A']++;

	int cnt = 0;
	for (int i = 0; i < 26; i++)
		if (arr[i] % 2 == 1)
			cnt++;

	if (cnt > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	for (int i = 0; i < 26; i++)
		for (int j = 0; j < arr[i] / 2; j++)
			ans += i + 'A';

	for (int i = 0; i < 26; i++)
		if (arr[i] % 2 == 1) ans += i + 'A';

	for (int i = 25; i >= 0; i--)
		for (int j = 0; j < arr[i] / 2; j++)
			ans += i + 'A';

	cout << ans;
}
