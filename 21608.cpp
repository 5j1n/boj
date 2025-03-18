#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[21][21];
vector<int>like[500], seq;
int n;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
int main() {
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int a;
		cin >> a;
		seq.push_back(a);
		for (int j = 0; j < 4; j++) {
			int tmp;
			cin >> tmp;
			like[a].push_back(tmp);
		}
	}

	for (int i = 0; i < n * n; i++) {
		vector<pair<int, int>>candidate;
		int me = seq[i];
		int like_adj = 0, empty_adj = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!arr[j][k]) {
					int like_cnt = 0;
					int empty_cnt = 0;
					for (int i = 0; i < 4; i++) {
						int nx = j + dx[i];
						int ny = k + dy[i];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (!arr[nx][ny]) empty_cnt++;
						else{
							for (int j = 0; j < 4; j++) {
								if (arr[nx][ny] == like[me][j]) {
									like_cnt++;
									break;
								}
							}
						}
					}
					if (like_adj < like_cnt || (like_adj == like_cnt && empty_adj < empty_cnt)) {
						candidate.clear();
						candidate.push_back({ j,k });
						like_adj = like_cnt;
						empty_adj = empty_cnt;
					}
					else if (like_adj == like_cnt && empty_adj == empty_cnt) {
						candidate.push_back({ j,k });
					}
				}
			}
		}
		sort(candidate.begin(), candidate.end(), cmp);
		arr[candidate[0].first][candidate[0].second] = me;
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				for (int l = 0; l < 4; l++) {
					if (arr[nx][ny] == like[arr[i][j]][l]) {
						cnt++;
						break;
					}
				}
			}
			if (cnt) ans += pow(10, cnt - 1);
		}
	}
	cout << ans;
}
