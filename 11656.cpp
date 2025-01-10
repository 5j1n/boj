#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;
	vector<string>v(str.length());

	for (int i = 0; i < v.size(); i++) {
		v[i] = str;
		str.erase(0, 1);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}
