#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int main() {
	string str;
	while (1) {
		//cin.ignore();
		getline(cin, str);
		bool flag = false;
		if (str == ".") break;
		stack<char>s;
		//cout << str << " --> 원래 문장\n";
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '[' || str[i] == '(') {
				s.push(str[i]);
				//cout << str[i] << "들어감\n";
			}
			else if (str[i] == ']') {
				if (!s.empty() && s.top() == '[') {
					//cout << s.top() << "빠짐\n";
					s.pop();

				}
				else {
					flag = true;
					break;
				}
			}
			else if (str[i] == ')') {
				if (!s.empty() && s.top() == '(') {
					//cout << s.top() << "빠짐\n";
					s.pop();
				}
				else {
					flag = true;
					break;
				}
			}
		}
		if (s.empty() && !flag) cout << "yes\n";
		else cout << "no\n";
	}

}
