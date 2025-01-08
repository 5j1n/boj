#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;

bool compare(int a, int b) {
	return a > b;
}
int main() {
	bool possible = false;
	string str;
	cin >> str;
	vector<char>v(str.length());
	vector<char>tmp;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0'&&!possible) {
			v[str.length() - 1] = '0';
			possible = true;
		}
		else {
			tmp.push_back(str[i]);
			cnt += str[i] - '0';
		}
	}

	if (!possible||cnt%3!=0) {
		cout << -1;
		return 0;
	}

	sort(tmp.begin(), tmp.end(), compare);

	for (int i = 0; i < tmp.size(); i++) {
		v[i] = tmp[i];
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}
