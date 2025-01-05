#include <iostream>
#include <string>

using namespace std;

string cro[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < 8; i++) {
		while (1) {
			int idx = str.find(cro[i]);
			if (idx == -1)
				break;
			str.replace(idx, cro[i].length(), "!");
		}
	}
	cout << str.length();
}
