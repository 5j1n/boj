#include <iostream>
#include <unordered_set>

using namespace std;

int n;
char game;
unordered_set<string>set;

int main() {
	cin >> n >> game;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		set.insert(str);
	}
	if (game == 'Y') cout << set.size();
	else if (game == 'F')cout << set.size() / 2;
	else cout << set.size() / 3;
}
