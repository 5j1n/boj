#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, vector<string>>name; // 그룹에 누가있음
unordered_map<string, string>group; // 누가 그 그룹임

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string input_group;
		int num;
		cin >> input_group;
		cin >> num;
		for (int j = 0; j < num; j++) {
			string input_name;
			cin >> input_name;
			name[input_group].push_back(input_name);
			group[input_name] = input_group;
		}
	}
	for (int i = 0; i < m; i++) {
		string who;
		cin >> who;
		int command;
		cin >> command;
		if (command) {
			cout << group[who] << "\n";
		}
		else {
			vector<string>tmp;
			for (int i = 0; i < name[who].size(); i++)
				tmp.push_back(name[who][i]);
			sort(tmp.begin(), tmp.end());
			for (int i = 0; i < tmp.size(); i++)
				cout << tmp[i] << "\n";
		}
	}
}
