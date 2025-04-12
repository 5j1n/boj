#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int ans;
bool visited[28];
unordered_set<int> strings[51];
int n, m;

void tracking(int idx, int cnt) {
	if (cnt + 5 == m) {
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			bool flag = true;
			for (auto it = strings[i].begin(); it != strings[i].end(); it++) {
				if (!visited[*it]) {
					flag = false;
					break;
				}
			}
			if (flag) tmp++;
		}
		ans = max(tmp, ans);
		return;
	}
	for (int i = idx; i < 27; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			tracking(i + 1, cnt + 1);
			visited[i] = 0;
		}
	}
	return;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			strings[i].insert(str[j] - 'a');

	}

	if (m < 5) {
		cout << 0;
		return 0;
	}
	visited[0] = visited[2] = visited[8] = visited[13] = visited[19] = 1;
	tracking(0, 0);
	cout << ans;
}
