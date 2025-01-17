#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int arr[101][101], visited[101][101];
int n, k, l, direct, time;
queue<pair<int, char>>q;
queue<pair<int, int>>snake;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 }; // D이면 +1 C이면 -1

void simul() {
	arr[1][1] = 2; // 자기 몸은 2, 사과는 1로 표시
	int curX = 1, curY = 1;
	snake.push({ 1,1 });
	time++;
	while (1) {
		int nx = curX + dx[direct];
		int ny = curY + dy[direct];

		if (nx<1 || ny<1 || nx>n || ny>n) return;
		if (arr[nx][ny] == 2) return;
		else if (arr[nx][ny] == 0) {
			arr[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}
		arr[nx][ny] = 2;
		snake.push({ nx,ny });
		curX = nx;
		curY = ny;
		if (!q.empty() && q.front().first == time) {
			if (q.front().second == 'D')
				direct = (direct + 1) % 4;
			else direct = (direct + 3) % 4;
			q.pop();
		}
		time++;
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char y;
		cin >> x >> y;
		q.push({ x,y });
	}

	simul();
	cout << time;
}
