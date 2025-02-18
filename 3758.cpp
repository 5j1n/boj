#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

struct Score {
	int team;
	int last;
	int num;
	int score;
};
int arr[101][101]; // 팀, 문제번호 별 최고 점수

bool cmp(Score a, Score b) {
	if (a.score == b.score) {
		if (a.num == b.num) {
			return a.last < b.last;
		}
		return a.num < b.num;
	}
	return a.score > b.score;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(arr, 0, sizeof(arr));
		vector<Score>Rank;
		int n, k, t, m;
		cin >> n >> k >> t >> m;
		Rank.resize(n);
		for (int i = 0; i < n; i++) {
			Rank[i].team = i + 1;
		}
		for (int l = 0; l < m; l++) {
			int i, j, s;
			cin >> i >> j >> s;
			arr[i][j] = max(arr[i][j], s);
			Rank[i-1].last = l;
			Rank[i-1].num++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= k; j++) {
				Rank[i].score += arr[i + 1][j];
			}
		}
		sort(Rank.begin(), Rank.end(),cmp);

		for (int i = 0; i < Rank.size(); i++) {
			if (Rank[i].team == t) {
				cout << i + 1 << "\n";
				break;
			}
			//cout << Rank[i].team << " "<<Rank[i].score<<" "<<Rank[i].num<<" "<<Rank[i].last<< " --\n";
		}
		//cout << "\n";
	}
}
