#include<iostream>
#include <set>
using namespace std;

int dp[10001];
set<string>Set[11];

int main() {
	int n, m;
	cin >> n >> m;
	dp[0] = 1;
	dp[1] = 1;
	Set[1].insert("1");
	dp[2] = 2;
	Set[2].insert("1+1");
	Set[2].insert("2");
	dp[3] = 4;
	Set[3].insert("1+2");
	Set[3].insert("1+1+1");
	Set[3].insert("2+1");
	Set[3].insert("3");

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		for (auto it = Set[i - 1].begin(); it != Set[i - 1].end(); it++) {
			string str = *it;
			str.append("+1");
			Set[i].insert(str);
		}
		for (auto it = Set[i - 2].begin(); it != Set[i - 2].end(); it++) {
			string str = *it;
			str.append("+2");
			Set[i].insert(str);
		}
		for (auto it = Set[i - 3].begin(); it != Set[i - 3].end(); it++) {
			string str = *it;
			str.append("+3");
			Set[i].insert(str);
		}
	}
	if (Set[n].size() < m) cout << -1;
	else {
		auto it = Set[n].begin();
		for (int i = 0; i < m - 1; i++) {
			it++;
		}
		cout << *it;
	}
	
}
