#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a<b;
	}
	return a.length() < b.length();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	set<string>set;
	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		set.insert(str);
	}
	vector<string>v(set.begin(),set.end());
	sort(v.begin(), v.end(), compare);


	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
}
