#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int>v;
unordered_map<int, string>map;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string name;
		int num = 0;
		cin >> name >> num;
		v.push_back(num);
		if (!map.count(num)) map[num] = name;
	}
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		int idx = lower_bound(v.begin(), v.end(), tmp) - v.begin();
		cout << map[v[idx]] << "\n";
	}
}
