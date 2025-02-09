#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	unordered_map<string, int>map;
	vector<pair<int, string>>v;
	for (int i = 1; i <= m; i++) {
		string str;
		cin >> str;
		map[str] = i;
	}
	for (auto it = map.begin(); it != map.end(); it++) {
		v.push_back({ it->second, it->first });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < min(n,int(v.size())); i++)
		cout << v[i].second << "\n";
}
