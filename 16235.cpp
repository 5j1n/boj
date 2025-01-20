#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree[11][11];
int nutri[11][11], cur[11][11];
int n, m, k;

int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> nutri[i][j];
			cur[i][j] = 5;
		}
	}

	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}

	int idx = 0;
	while (1) {
		if (idx / 4 == k) {

			break;
		}
		if (idx % 4 == 0) { //봄

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (tree[i][j].size() > 0) {
						sort(tree[i][j].begin(), tree[i][j].end());
						bool flag = true;
						for (int k = 0; k < tree[i][j].size(); k++) {
							if (cur[i][j] - tree[i][j][k] < 0) {
								flag = false;
							}
							if (!flag) tree[i][j][k] *= -1;
							else {
								cur[i][j] -= tree[i][j][k];
								tree[i][j][k]++;	
							}
						}
					}
				}
			}
		}
		else if (idx % 4 == 1) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (tree[i][j].size() > 0) {
						sort(tree[i][j].begin(), tree[i][j].end(),cmp);
						for (int k = tree[i][j].size() - 1; k > -1; k--) {
							if (tree[i][j][k] > 0) break;
							cur[i][j] += (-1 *tree[i][j][k]) / 2;
							tree[i][j].pop_back();
						}
					}
				}
			}
		}
		else if (idx % 4 == 2) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (tree[i][j].size() > 0) {
						sort(tree[i][j].begin(), tree[i][j].end());
						for (int k = tree[i][j].size() - 1; k > -1; k--) {
							if (tree[i][j][k] % 5 == 0) {
								for (int l = 0; l < 8; l++) {
									int nx = i + dx[l];
									int ny = j + dy[l];
									if (nx<1 || ny<1 || nx>n || ny>n) continue;

									tree[nx][ny].push_back(1);
								}

							}
						}
					}
				}
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cur[i][j] += nutri[i][j];
				}
			}
		}
		idx++;

		
	}


	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += tree[i][j].size();
		}
	}
	cout << ans;

}
