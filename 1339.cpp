#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[27], num[27];
vector<pair<int, char>>v;
vector<string>string_vec;

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		string_vec.push_back(str);
		int idx = 1;
		for (int i = str.size() - 1; i > -1; i--) {
			arr[str[i] - 'A'] += pow(10,str.size()-i);
			idx++;
		}
	}

	for (int i = 0; i < 27; i++) {
		if (arr[i] > 0)v.push_back({ arr[i],i + 'A' });
	}

	sort(v.begin(), v.end());

	int idx = 0;
	for (int i = v.size() - 1; i > -1; i--) {
		num[v[i].second - 'A'] = 9 - idx;
		idx++;
	}

	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < string_vec[i].size(); j++) {
			tmp = tmp * 10 + num[string_vec[i][j] - 'A' ];
		}
		ans += tmp;
	}

	cout << ans;
}
