#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[100][100];
int arr[100][100], tmp[100][100];
int N, Q, ans1, ans2;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void rotate(int x, int y, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[j + x][n - i + y- 1] = arr[i + x][j + y];
			//cout << i + x << " " << j + y << "=>" << j + y << " " << n - i + x - 1 << "\n";
		}
	}

}

void rotate(int n) {
	for (int i = 1; i <= N; i += n) {
		for (int j = 1; j <= N; j += n) {
			//cout << i << " " << j << "\n";
			rotate(i, j, n);
		}
	}

	memcpy(arr, tmp, sizeof(arr));
}

void melt() {
	memcpy(tmp, arr, sizeof(tmp));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx<1 || ny<1 || nx>N || ny>N) continue;
				if (arr[nx][ny])cnt++;
			}
			if (cnt < 3) tmp[i][j] = max(0, arr[i][j] - 1);
			else tmp[i][j] = arr[i][j];
			
		}
	}
	memcpy(arr, tmp, sizeof(arr));
}

int bfs(int i, int j) {
	int ret = 1;
	queue<pair<int, int>>q;
	q.push({ i,j });
	visited[i][j] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx<1 || ny<1 || nx>N || ny>N) continue;
			if (visited[nx][ny] || !arr[nx][ny]) continue;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
			ret++;
		}
	}
	return ret;
}

void output() {
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin >> N >> Q;
	N = pow(2, N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= Q; i++) {
		int l;
		cin >> l;
		l = pow(2, l);
		rotate(l);
		//output();
		melt();
		//output();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j]) {
				ans1+=arr[i][j];
				if (!visited[i][j]) {
					ans2 = max(ans2,bfs(i,j));
				}
			}
		}
	}

	cout << ans1 << "\n" << ans2 << "\n";
}
