#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<pair<int,string>>>v;

bool cmp(pair<int, string>a, pair<int, string>b) {
	return a.second < b.second;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		string name;
		cin >> num >> name;
		bool flag = false;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].size() < m && abs(v[i][0].first - num) <= 10) {
				flag = true;
				v[i].push_back({ num,name });
				break;
			}
		}
		if (!flag) {
			v.push_back(vector < pair<int, string>>());
			v[v.size() - 1].push_back({ num,name });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i].size() == m)
			cout << "Started!\n";
		else cout << "Waiting!\n";
		sort(v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j].first << " " << v[i][j].second << "\n";
		}
	}
}
