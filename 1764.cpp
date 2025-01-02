#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
	int n, m;
	unordered_set<string>set;
	vector<string>v;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		set.insert(str);
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (set.count(str) > 0)
			v.push_back(str);
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}
