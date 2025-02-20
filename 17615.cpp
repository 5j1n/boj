#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int ans1, ans2, ans3, ans4;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	string str;
	cin >> n;
	cin >> str;
	string tmp = str;
	set<int>r_set, b_set;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'R') r_set.insert(i);
		else b_set.insert(i);
	}
	set<int>r_tmp, b_tmp;
	r_tmp = r_set;
	b_tmp = b_set;
	for (int i = str.size() - 2; i > -1; i--) {
		if (tmp[i] == 'R' && tmp[i + 1] == 'B') {
			auto it = b_tmp.end();
			it--;
			swap(tmp[i], tmp[*it]);
			b_tmp.erase(*it);
			b_tmp.insert(i);
			ans1++;
		}
	}
	tmp = str;
	r_tmp = r_set;
	b_tmp = b_set;
	for (int i = str.size() - 2; i > -1; i--) {
		if (tmp[i] == 'B' && tmp[i + 1] == 'R') {
			auto it = r_tmp.end();
			it--;
			swap(tmp[i], tmp[*it]);
			r_tmp.erase(*it);
			r_tmp.insert(i);
			ans2++;
		}
	}
	tmp = str;
	r_tmp = r_set;
	b_tmp = b_set;
	for (int i = 1; i < str.size(); i++) {
		if (tmp[i] == 'B' && tmp[i - 1] == 'R') {
			auto it = r_tmp.begin();
			swap(tmp[i], tmp[*it]);
			r_tmp.erase(*it);
			r_tmp.insert(i);
			ans3++;
		}
	}
	tmp = str;
	r_tmp = r_set;
	b_tmp = b_set;
	for (int i = 1; i < str.size(); i++) {
		if (tmp[i] == 'R' && tmp[i - 1] == 'B') {
			auto it = b_tmp.begin();
			swap(tmp[i], tmp[*it]);
			b_tmp.erase(*it);
			b_tmp.insert(i);
			ans4++;
		}
	}
	cout << min(min(ans1, ans2), min(ans3, ans4));
}
