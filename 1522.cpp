#include <iostream>
#include <climits>

using namespace std;

int a_cnt, b_cnt, ans1 = INT_MAX, ans2 = INT_MAX;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a') a_cnt++;
		else b_cnt++;
	}
	for (int i = 0; i < str.size() - a_cnt; i++) {
		int tmp = 0;
		for (int j = i; j < i + a_cnt; j++) {
			if (str[j] == 'b') tmp++;
		}
		ans1 = min(tmp, ans1);
	}
	for (int i = 0; i < str.size() - b_cnt; i++) {
		int tmp = 0;
		for (int j = i; j < i + b_cnt; j++) {
			if (str[j] == 'a') tmp++;
		}
		ans2 = min(tmp, ans2);
	}

	cout << min(ans1, ans2);

}
