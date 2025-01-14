#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

char arr[12][6], copy[12][6];
bool visited[12][6];
vector<pair<int, int>>v;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int check(int x, int y, char color) {
	int num = 1;
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = true;
	v.push_back({ x,y });
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx>11 || ny>5) continue;
			if (arr[nx][ny] != color || visited[nx][ny]) continue;
			q.push({ nx,ny });
			visited[nx][ny] = true;
			num++;
			v.push_back({ nx,ny });
		}
	}
	return num;
}

void drop() {
	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != '.') {
				int nxt = i + 1;
				while (nxt < 12 && arr[nxt][j] == '.') {
					nxt++;
				}
				if (nxt > i + 1) {
					arr[nxt - 1][j] = arr[i][j];
					arr[i][j] = '.';
				}
			}
		}
	}
}

int main() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> arr[i][j];
	int ans = 0;
	while (1) {
		bool flag = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] != '.'&&!visited[i][j]) {
					v.clear();
					if (check(i, j, arr[i][j]) > 3) {
						flag = true;
						for (int i = 0; i < v.size(); i++)
							arr[v[i].first][v[i].second] = '.';
					}
				}
			}
		}
		
		if (!flag) {
			break;
		}
		else {
			drop();
			ans++;
		}
		
	}
	cout << ans;
}
