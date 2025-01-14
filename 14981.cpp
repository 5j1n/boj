#include<iostream>
#include <deque>
#include <vector>
using namespace std;

deque<char>status[5];
int k;

vector<int> valid(int target) {
	vector<int>tmp;
	tmp.push_back(target);
	int nxt = target + 1;
	int pre = target;
	while (nxt < 5) {
		if (status[pre][2] != status[nxt][6]) {
			tmp.push_back(nxt);
			nxt++;
			pre++;
		}
		else break;
	}
	nxt = target - 1;
	pre = target;
	while (nxt > 0) {
		if (status[pre][6] != status[nxt][2]) {
			tmp.push_back(nxt);
			nxt--;
			pre--;
		
		}
		else break;
	}
	return tmp;
}
void simul(int target, int turn) {
	vector<int>v = valid(target);
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == target % 2) {
			if (turn == 1) {
				status[v[i]].push_front(status[v[i]].back());
				status[v[i]].pop_back();
			}
			else {
				status[v[i]].push_back(status[v[i]].front());
				status[v[i]].pop_front();
			}
		}
		else {
			if (turn == 1) {
				status[v[i]].push_back(status[v[i]].front());
				status[v[i]].pop_front();
			}
			else {
				status[v[i]].push_front(status[v[i]].back());
				status[v[i]].pop_back();
			}
		}
	}
}
int main() {
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 9; j++) {
			char tmp;
			cin >> tmp;
			status[i].push_back(tmp);
		}
	}

	cin >> k;
	while (k--) {
		int target, turn;
		cin >> target >> turn;
		simul(target, turn);
	}
	int score = 1;
	int ans = 0;
	for (int i = 1; i < 5; i++) {
		if (status[i].front()=='1') {
			ans += score;
		}
		score *= 2;
	}
	cout << ans;
}
