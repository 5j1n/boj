#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	return a > b;
}
int main() {
	int n;
	unordered_set<string>set;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, commute;
		cin >> name >> commute;
		if (commute == "enter") set.insert(name);
		else set.erase(name);
	}
	vector<string>v(set.begin(), set.end());
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
}
