#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int problem[100001], algorithm[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	unordered_map<int, set<int>>map;
	unordered_map<int, set<pair<int,int>>>algo;
	set<int>easy_first;
	cin >> n;
	while (n--) {
		int num, hard, classify;
		cin >> num >> hard >> classify;

		easy_first.insert(hard);
		map[hard].insert(num);
		algo[classify].insert({ hard,num });
		problem[num] = hard;
		algorithm[num] = classify;
	}


	cin >> n;
	while (n--) {
		string command;
		cin >> command;
		if (command == "recommend") {
			int tmp_algo, x;
			cin >> tmp_algo >> x;
			if (x == 1) {
				auto hard = algo[tmp_algo].end();
				hard--;
				cout << hard->second << "\n";
			}
			else {
				auto hard = algo[tmp_algo].begin();
				cout << hard->second<< "\n";
			}
		}
		else if (command == "recommend2") {
			int Num;
			cin >> Num;
			if (Num == 1) {
				auto hard = easy_first.end();
				hard--;
				auto prob = map[*hard].end();
				prob--;
				cout << *prob << "\n";
			}
			else {
				auto hard = easy_first.begin();
				auto prob = map[*hard].begin();

				cout << *prob << "\n";
			}
		}
		else if (command == "recommend3"){
			int Num;
			cin >> Num;
			int mini;
			cin >> mini;
			auto hard = easy_first.lower_bound(mini);
			if (Num == 1) {
				if (hard == easy_first.end()) {
					cout << "-1\n";
				}
				else {
					auto prob = map[*hard].begin();
					cout << *prob << "\n";
				}
			}
			else {
				if (hard == easy_first.begin()) {
					cout << "-1\n";
				}
				else {
					hard--;
					auto prob = map[*hard].end();
					prob--;
					cout << *prob << "\n";
				}
			}
		}
		else if (command == "add") {
			int Num, hard, classify;
			cin >> Num >> hard >> classify;
			easy_first.insert(hard);
			map[hard].insert(Num);
			problem[Num] = hard;
			algorithm[Num] = classify;
			algo[classify].insert({ hard,Num });
		}
		else {
			int Num = 0;
			cin >> Num;
			int hard = problem[Num];
			int tmp_algo = algorithm[Num];
			map[hard].erase(Num);
			algo[tmp_algo].erase({ hard,Num });
			problem[Num] = 0;
			if (map[hard].size() == 0) {
				easy_first.erase(hard);
				map.erase(hard);
			}
			if (algo[tmp_algo].size() == 0) {
				algo.erase(tmp_algo);
			}

		}
	}
}
