#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int problem[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	unordered_map<int, set<int>>map;
	set<int>easy_first;
	cin >> n;
	while (n--) {
		int num, hard;
		cin >> num >> hard;

		easy_first.insert(hard);
		map[hard].insert(num);
		problem[num] = hard;
	}
	

	cin >> n;
	while (n--) {
		string command;
		cin >> command;
	
		if (command == "recommend") {
			int Num;
			cin >> Num;
			if (Num == 1) {
				auto hard = easy_first.end();
				hard--;
				auto prob = map[*hard].end();
				prob--;
				cout << *prob<<"\n";
			}
			else {
				auto hard = easy_first.begin();
				auto prob = map[*hard].begin();

				cout << *prob << "\n";
			}
		}
		else if (command == "add") {
			int Num, hard;
			cin >> Num >> hard;
			easy_first.insert(hard);
			map[hard].insert(Num);
			problem[Num] = hard;
		}
		else {
			int Num = 0;
			cin >> Num;
			int hard = problem[Num];
			map[hard].erase(Num);
			problem[Num] = 0;
			if (map[hard].size() == 0) {
				easy_first.erase(hard);
				map.erase(hard);
			}

		}
	}
}
