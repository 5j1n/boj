#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

bool flag[3]; //0: 모음 하나는 있는가? true 1: 3개연속이 있는가? true 2. 두 같은 글자 연속인가? true
int mo, ja;

unordered_set<char>set;
int main() {
	set.insert('a');
	set.insert('e');
	set.insert('i');
	set.insert('o');
	set.insert('u');

	while (1) {
		string str;
		cin >> str;
		if (str == "end") break;
		mo = ja = 0;
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < str.size(); i++) {
			if (set.count(str[i])) {
				if (mo > 0) mo++;
				else {
					ja = 0;
					mo = 1;
				}
				
				flag[0] = true;
			}
			else {
				if (ja > 0) ja++;
				else {
					mo = 0;
					ja = 1;
				}
				
			}

			if (mo == 3 || ja == 3) {
				flag[1] = true;
				break;
			}

			if (i < str.size() - 1) {
				if (str[i] == str[i + 1]) {
					if (str[i] == 'e' || str[i] == 'o')
						continue;
					else {
						flag[2] = true;
						break;
					}
				}
			}

		}
		cout << "<" << str << "> is ";
		if (flag[1] || flag[2] || !flag[0]) {
			cout << "not ";
		}
		cout << "acceptable.\n";
	}
}
