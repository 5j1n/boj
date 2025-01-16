#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string>map;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string site, pw;
		cin >> site >> pw;
		map[site] = pw;
	}
	for (int i = 0; i < m; i++) {
		string site;
		cin >> site;
		cout << map[site] << "\n";
	}
}
