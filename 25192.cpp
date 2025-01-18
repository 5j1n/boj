#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	set<string>set;
	while (n--) {
		string str;
		cin >> str;
		if (str == "ENTER") {
			set.clear();
		}
		else {
			if (set.count(str) == 0) {
				ans++;
				set.insert(str);
			}
		}
	}

	cout << ans;
}
