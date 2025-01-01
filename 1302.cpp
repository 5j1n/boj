#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n, ans = 0;
	string ansStr;
	cin >> n;
	map<string, int>map;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		map[str]++;
		if (ans < map[str]) {
			ans = map[str];
			ansStr = str;
		}
		else if (ans == map[str]) {
			ansStr = min(ansStr, str);
		}
	}

	cout << ansStr;
}
