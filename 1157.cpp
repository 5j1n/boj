#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

string str;

map<char, int>Map;
vector<pair<int, char>>v;
int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
		Map[str[i]]++;
	}
	for (auto it = Map.begin(); it != Map.end(); it++) {
		v.push_back({ it->second,it->first });
	}
	sort(v.begin(), v.end());
	if (v.size() == 1) cout << v[0].second;
	else {
		//cout << v[v.size() - 1].first << " " << v[v.size() - 2].first << "\n";
		if (v[v.size() - 1].first == v[v.size() - 2].first) cout << "?";
		else cout << v[v.size() - 1].second;
	}
}
