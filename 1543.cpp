#include <iostream>
#include <string>
using namespace std;

int main() {
	int ans = 0;
	string str, find;
	getline(cin, str);
	getline(cin, find);
	for (int i = 0; i < str.length(); i++) {
		bool flag = true;
		for (int j = 0; j < find.length(); j++) {
			if (str[i + j] != find[j]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			ans++;
			i += find.length() - 1;
		}
	}

	cout << ans;
}
