#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<char, int>map;
unordered_set<char>set;
int ans;

int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		map[str[i]]++;
		set.insert(str[i]);
	}
	n--;

	while (n--) {
		unordered_set<char>tmp_set = set;
		string tmp;
		cin >> tmp;
		int cmp = 0;
		unordered_map<char, int>tmp_map;
		for (int i = 0; i < tmp.size(); i++)
		{
			tmp_set.insert(tmp[i]);
			tmp_map[tmp[i]]++;
		}
		for (auto it = tmp_set.begin(); it != tmp_set.end(); it++) {
			cmp += abs(map[*it] - tmp_map[*it]);
		}

		if (cmp <= 1) ans++;
		else if (cmp == 2 && tmp.size() == str.size()) ans++;

	}
	cout << ans;
}
