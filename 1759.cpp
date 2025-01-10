#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string>ans;
vector<char>arr;

int n, m;
char mo[5] = { 'a', 'e', 'i', 'o', 'u' };
string str;
void tracking(int start, int size) {
	if (size == n) {
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < str.length(); i++) {
			bool flag = false;
			for (int j = 0; j < 5; j++) {
				if (str[i] == mo[j]) {
					cnt1++;
					flag = true;
					break;
				}
			}
			if (!flag) cnt2++;
		}
		if (cnt1 > 0 && cnt2 > 1)ans.push_back(str);
		return;
	}

	for (int i = start; i < m; i++) {
		str.push_back(arr[i]);
		tracking(i + 1, size + 1);
		str.pop_back();
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	tracking(0,0);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}
