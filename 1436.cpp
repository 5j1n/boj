#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, val = 666, cnt = 0;
	cin >> n;
	while (1) {
		string str = to_string(val);
		for (int i = 0; i < str.length() - 2; i++)
		{
			if (str[i] == '6'&& str[i + 1] == '6'&& str[i + 2] == '6')
			{
				cnt++;
				break;
			}
		}
		if (cnt == n) {
			cout << val;
			return 0;
		}
		val++;
	}
}
