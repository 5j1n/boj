#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> circul;
vector < pair<int, pair<int, int>>>v;
int arr[1001][1001];
int tmp[1001][1001];

int r, c, t, ans;
int dx[] = {-1,1,0,0 };
int dy[] = {0,0,-1,1 };

int main() {
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				circul.push_back({ i,j });
			}
			else if (arr[i][j] > 0) {
				v.push_back({ arr[i][j],{i,j} });
			}
		}
	}
	for (int i = 1; i <= t; i++) {
		memset(tmp, 0, sizeof(tmp));
		for (int j = 0; j < v.size(); j++) {
			int val = v[j].first;
			int x = v[j].second.first;
			int y = v[j].second.second;
			int cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
				if (arr[nx][ny] == -1) continue;

				tmp[nx][ny] += arr[x][y] / 5;
			}

			tmp[x][y] += (arr[x][y] - (cnt * (arr[x][y]/ 5)));
			
		}
		for (int i = 0; i < circul.size(); i++) {
			tmp[circul[i].first][circul[i].second] = -1;
		}
		memcpy(arr, tmp, sizeof(arr));
		for (int j = 0; j < circul.size(); j++) {
			int x = circul[j].first;
			int y = circul[j].second;

			if (!j) {
				for (int k = x; k > 0; k--) {
					arr[k][y] = arr[k - 1][y];
					if (k == x) arr[k][y] = -1;
				}
				for (int k = 0; k < c - 1; k++) {
					arr[0][k] = arr[0][k + 1];
				}
				for (int k = 0; k < x; k++) {
					arr[k][c - 1] = arr[k + 1][c - 1];
				}
				for (int k = c - 1; k > 0; k--) {
					arr[x][k] = arr[x][k - 1];
					if (arr[x][k - 1] == -1) arr[x][k] = 0;
				}
			}

			else {
				
				for (int k = x; k < r - 1; k++) {
					arr[k][y] = arr[k + 1][y];
					if (k == x) arr[k][y] = -1;
				}
				for (int k = 0; k < c -1; k++) {
					arr[r-1][k] = arr[r-1][k + 1];
				}

				for (int k = r; k > x; k--) {
					arr[k-1][c - 1] = arr[k-2][c - 1];
				}

				for (int k = c - 1; k > 0; k--) {
					arr[x][k] = arr[x][k - 1];
					if (arr[x][k - 1] == -1) arr[x][k] = 0;
				}
			}
		}

		v.clear();
		ans = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j]>0) {
					v.push_back({ arr[i][j],{i,j} });
					ans += arr[i][j];
				}
			}
		}
	}
	cout << ans;
}
