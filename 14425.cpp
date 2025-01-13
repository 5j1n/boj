#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	unordered_set<string>set;
	int n, m, ans = 0;
	cin >> n >> m;
	while (n--) {
		string str;
		cin >> str;
		set.insert(str);
	}
	while (m--) {
		string str;
		cin >> str;
		if (set.count(str)>0) ans++;
	}
	cout << ans;
}
