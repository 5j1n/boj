#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;
vector<string>ans;
string compare;
int n;
bool visited[10];

void tracking(int idx, int cnt) {
	if (cnt == n+1) {
		string tmp = "";
		for (int i = 0; i < cnt; i++) {
			tmp.push_back(v[i] + '0');
		}
		ans.push_back(tmp);
		return;
	}

	if (v.size()) {
		if (compare[v.size() - 1] == '>') {
			for (int i = 0; i < v[v.size() - 1]; i++) {
				if (!visited[i]) {
					visited[i] = 1;
					v.push_back(i);
					tracking(i, cnt + 1);
					v.pop_back();
					visited[i] = 0;
				}
			}
		}
		else {
			for (int i = v[v.size() - 1] + 1; i < 10; i++) {
				if (!visited[i]) {
					visited[i] = 1;
					v.push_back(i);
					tracking(i, cnt + 1);
					v.pop_back();
					visited[i] = 0;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (!visited[i]) {
				visited[i] = 1;
				v.push_back(i);
				tracking(i, cnt + 1);
				v.pop_back();
				visited[i] = 0;
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;
		compare.push_back(tmp);
	}
	tracking(0, 0);
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << "\n";
	cout << ans[0];
}
