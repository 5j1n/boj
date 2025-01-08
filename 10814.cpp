#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, string>>a, pair<int, pair<int, string>>b) {
	if (a.second.first == b.second.first) {
		return a.first < b.first;
	}
	else
		return a.second.first < b.second.first;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, pair<int, string>>>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].second.first >> v[i].second.second;
		v[i].first = i;
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << v[i].second.first << " " << v[i].second.second << "\n";
	}
}
