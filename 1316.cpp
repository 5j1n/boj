#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		bool isFluent = true;
		unordered_map<char, int>map;
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (i>0&&map[str[i]] > 0 && str[i - 1] != str[i])
			{
				isFluent = false;
				break;
			}
			else map[str[i]]++;

		}
		if (isFluent) ans++;
	}
	cout << ans;
}
