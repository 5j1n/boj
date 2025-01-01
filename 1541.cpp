#include <iostream>
#include <string>
using namespace std;

int main() {
	string str, valStr="";
	int val=0;
	bool minus = false;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-' && !minus) {
			val += stoi(valStr);
			minus = true;
			valStr.clear();
		}
		else if (str[i] == '-' && minus) {
			val -= stoi(valStr);
			valStr.clear();
		}
		else if (str[i] == '+' && minus) {
			val -= stoi(valStr);
			valStr.clear();
		}
		else if (str[i] == '+' && !minus) {
			val += stoi(valStr);
			valStr.clear();
		}
		else
			valStr.push_back(str[i]);
	}
	if (minus) val -= stoi(valStr);
	else val += stoi(valStr);
	cout << val;
}
