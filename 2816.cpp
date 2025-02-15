#include <iostream>
#include <algorithm>

using namespace std;

int kbs_idx, kbs2_idx;
string ans;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "KBS1") kbs_idx = i;
		else if (str == "KBS2") kbs2_idx = i;
	}
	for (int i = 0; i < kbs_idx; i++) {
		ans.append("1");
	}
	for (int i = 0; i < kbs_idx; i++) {
		ans.append("4");
	}
	if (kbs_idx > kbs2_idx) kbs2_idx++;
	if (kbs2_idx != 1) {
		for (int i = 0; i < kbs2_idx; i++) {
			ans.append("1");
		}
		for (int i = 1; i < kbs2_idx; i++) {
			ans.append("4");
		}
	}
	cout << ans<<"\n";
}
