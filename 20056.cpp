#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Fire {
	int r;
	int c;
	int m;
	int s;
	int d;
};

vector<Fire> cnt[51][51], tmp_cnt[51][51];
int n, m, k;
pair<int, int> dir[8] = { {-1,0},{-1,1},{0,1},{1,1},{1,0}, {1,-1},{0,-1},{-1,-1} };

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;;
		cnt[r][c].push_back({r,c,m,s,d});
	}
	
	for (int i = 1; i <= k; i++) {
		vector<Fire>tmp_cnt[51][51];
		for (int j = 1; j <=n; j++) {
			for (int l = 1; l <= n; l ++) {
				for (int m = 0; m < cnt[j][l].size(); m++) {
					Fire fire = cnt[j][l][m];
					int nx = fire.r + fire.s * dir[fire.d].first;
					int ny = fire.c + fire.s * dir[fire.d].second;
					if (nx <= 0) nx = (nx + 1001 * n) % n;
					else if (nx > n) nx = nx % n;

					if (ny <= 0) ny = (ny + 1001 * n) % n;
					else if (ny > n) ny = ny % n;

					if (!nx) nx = n;
					if (!ny) ny = n;
					tmp_cnt[nx][ny].push_back({ nx,ny,fire.m,fire.s,fire.d });
				}
			}
		}

		for (int j = 1; j <= n; j++) {
			for (int l = 1; l <= n; l++) {
				cnt[j][l] = tmp_cnt[j][l];
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cnt[i][j].size()>=2) {
					int tmp_m = 0, tmp_s = 0, odd_even = -1;
					for (int l = 0; l < cnt[i][j].size(); l++) {
						tmp_m += cnt[i][j][l].m;
						tmp_s += cnt[i][j][l].s;
						if (odd_even == -1) {
							if (cnt[i][j][l].d % 2) odd_even = 1;
							else odd_even = 0;
						}
						else if (!odd_even && cnt[i][j][l].d % 2)
							odd_even = 2;
						else if (odd_even == 1 && cnt[i][j][l].d % 2 == 0)
							odd_even = 2;
					}
					tmp_m /= 5;
					tmp_s /= cnt[i][j].size();
					cnt[i][j].clear();
					if (tmp_m) {
						if (!odd_even||odd_even==1) {
							for (int l = 0; l <= 6; l += 2) {
								cnt[i][j].push_back({ i,j,tmp_m,tmp_s,l });
							}
						}
						else {
							for (int l = 1; l <= 7; l += 2) {
								cnt[i][j].push_back({ i,j,tmp_m,tmp_s,l });
							}
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int l = 0; l < cnt[i][j].size(); l++) {
				ans += cnt[i][j][l].m;
			}
		}
	}
	cout << ans;
}
