#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string>set;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		set.insert(str);
	}

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		string tmp = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ',') {
				if (set.count(tmp)) set.erase(tmp);
				tmp = "";
			}
			else tmp += str[i];

			if (i == str.size() - 1) {
				if (set.count(tmp)) set.erase(tmp);
				tmp = "";
			}
		}
		cout << set.size()<<"\n";
	}
	
}
