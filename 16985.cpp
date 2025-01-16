#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

bool arr[6][6][6], cop[6][6][6],tmp[6][6][6]; //높이, 행, 열 순
int visited[6][6][6];
int ans = 987654321;
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int height[6], turn[6];
bool check[6];

bool choose_floor(int tmp) {
	memset(height, 0, sizeof(height));
	memset(check, false, sizeof(check));
	for (int j = 1; j < 6; j++) {
		height[j] = tmp % 5 + 1;
		tmp = tmp / 5;
		check[height[j]] = true;
	}
	bool flag = false;
	for (int j = 1; j < 6; j++) {
		if (!check[j]) {
			flag = true;
			break;
		}
	}
	return flag;
}

int bfs() {
	int tmp_ans = 987654321;
	memset(visited, -1, sizeof(visited));
	queue<pair<int, pair<int, int>>>q;
	visited[1][1][1] = 0;
	q.push({ 1,{1,1 } });
	while (!q.empty()) {
		int curZ = q.front().first;
		int curX = q.front().second.first;
		int curY = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = curZ + dz[i];
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx < 1 || ny < 1 || nz < 1 || nx>5 || ny>5 || nz>5) continue;
			if (cop[nz][nx][ny] == false || visited[nz][nx][ny] > -1) continue;
			visited[nz][nx][ny] = visited[curZ][curX][curY] + 1;
			q.push({ nz,{nx,ny} });
		}
	}
	
	if (visited[5][5][5] > -1) {	
		//cout << visited[5][5][5] << "\n";
		tmp_ans = min(tmp_ans, visited[5][5][5]);
		/*cout << "-----\n";
		for (int i = 1; i < 6; i++) {
			for (int j = 1; j < 6; j++) {
				for (int k = 1; k < 6; k++) {
					cout << cop[i][j][k];
				}
				cout << "\n";
			}
			cout << "\n";
		}
		cout << "-----\n\n";*/
	}
	return tmp_ans;
}

int shuff() {
	int tmp_ans = 987654321;
	for (int i = 0; i < 1024; i++) {
		memset(turn, 0, sizeof(turn));
		int tmp = i;
		for (int j = 1; j < 6; j++) {
			turn[j] = tmp % 4;
			tmp = tmp / 4;

			if (turn[j] == 0) {
				for (int k = 1; k < 6; k++) {
					for (int l = 1; l < 6; l++) {
						cop[height[j]][k][l] = arr[j][k][l];
					}
				}
			}
			else if (turn[j] == 1) {
				for (int k = 1; k < 6; k++) {
					for (int l = 1; l < 6; l++) {
						cop[height[j]][l][6 - k] = arr[j][k][l];
					}
				}
			}
			else if (turn[j] == 2) {
				for (int k = 1; k < 6; k++) {
					for (int l = 1; l < 6; l++) {
						cop[height[j]][6 - k][6 - l] = arr[j][k][l];
					}
				}
			}
			else {
				for (int k = 1; k < 6; k++) {
					for (int l = 1; l < 6; l++) {
						cop[height[j]][6 - l][k] = arr[j][k][l];
					}
				}
			}
		}

		/*for (int j = 1; j < 6; j++) {
			cout << turn[j] << " ";
		}
		cout << "\n";*/
		/*cout << "-----\n";
		for (int i = 1; i < 6; i++) {
			for (int j = 1; j < 6; j++) {
				for (int k = 1; k < 6; k++) {
					cout << cop[i][j][k];
				}
				cout << "\n";
			}
			cout << "\n";
		}
		cout << "-----\n\n";*/
		if (cop[1][1][1]) tmp_ans = min(tmp_ans, bfs());
		if (tmp_ans == 12) break;
	}
	return tmp_ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 6; j++)
			for (int k = 1; k < 6; k++)
				cin >> arr[i][j][k];

	for (int i = 0; i < 3125; i++) {
		bool flag = choose_floor(i);
		if (!flag) {
			ans = min(ans, shuff());
			if (ans == 12) break;
		}
		//cout << i << "\n";
	}
	if (ans == 987654321) ans = -1;
	cout << ans;



}
