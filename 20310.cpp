#include <iostream>
#include <vector>

using namespace std;

int zero, one;
vector<char>v;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		v.push_back(str[i]);
		if (str[i] == '1') one++;
		else zero++;
	}
	//cout << zero << " " << one << "\n";
	int tmp = 0;
	for (int i = 0; i < str.size(); i++) {
		if (v[i] == '1') {
			v.erase(v.begin() + i);
			i--;
			tmp++;
		}
		if (tmp == one / 2) break;
	}
	tmp = 0;
	for (int i = v.size() - 1; i > -1; i--) {
		if (v[i] == '0') {
			v.erase(v.begin() + i);
			tmp++;
		}
		if (tmp == zero / 2) break;
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}
