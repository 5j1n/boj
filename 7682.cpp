#include <iostream>
#include <cstring>

using namespace std;

int x, o, dot;
char arr[3][3];

int main() {
	while (1) {
		bool x_win = false, o_win = false, ans = false;
		x = o = dot = 0;
		memset(arr, '-', sizeof(arr));
		string str;
		cin >> str;
		if (str == "end") break;

		for (int i = 0; i < 9; i++) {
			arr[i / 3][i % 3] = str[i];
			if (str[i] == 'X') x++;
			else if (str[i] == 'O') o++;
			else dot++;
		}

		for (int i = 0; i < 3; i++) {
			if (arr[i][0] == 'O' && arr[i][1] == 'O' && arr[i][2] == 'O')
				o_win = true;
		}
		for (int i = 0; i < 3; i++) {
			if (arr[0][i] == 'O' && arr[1][i] == 'O' && arr[2][i] == 'O')
				o_win = true;
		}
		if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O')
			o_win = true;
		if (arr[2][0] == 'O' && arr[1][1] == 'O' && arr[0][2] == 'O')
			o_win = true;

		for (int i = 0; i < 3; i++) {
			if (arr[i][0] == 'X' && arr[i][1] == 'X' && arr[i][2] == 'X')
				x_win = true;
		}
		for (int i = 0; i < 3; i++) {
			if (arr[0][i] == 'X' && arr[1][i] == 'X' && arr[2][i] == 'X')
				x_win = true;
		}
		if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')
			x_win = true;
		if (arr[2][0] == 'X' && arr[1][1] == 'X' && arr[0][2] == 'X')
			x_win = true;

		if (!o_win && !x_win && o == 4 && x == 5) ans = true;
		else if (o_win && !x_win && o == x) ans = true;
		else if (!o_win && x_win && o + 1 == x) ans = true;
		else ans = false;

		if (ans) cout << "valid\n";
		else cout << "invalid\n";
	}
}
