#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	set<int>set;
	vector<int>val;
	unordered_map<int, int>map;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		set.insert(tmp);
		val.push_back(tmp);
	}
	vector<int>v(set.begin(),set.end());
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		map[v[i]] = i;
	}
	for (int i = 0; i < val.size(); i++) {
		cout << map[val[i]]<<" ";
	}
	

}
