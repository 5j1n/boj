#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int main() {
	string str;
	cin >> str;
	vector<int>v(str.length());
	for (int i = 0; i < str.length(); i++) {
		v[i] = str[i] - '0';
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}
