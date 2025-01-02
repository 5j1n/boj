#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	unordered_map<string, int>map1;
	unordered_map<int, string>map2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		map1[str] = i;
		map2[i] = str;
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (str[0] > '0' && str[0] <= '9') {
			cout << map2[stoi(str)] << "\n";
		}
		else cout << map1[str]<<"\n";
	}
}
