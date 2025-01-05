#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n;
char arr[26][26];
bool visited[26][26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx > n || ny > n || nx < 1 || ny < 1) continue;
			if (arr[nx][ny] == '0' || visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
			cnt++;
		}
	}
	return cnt;
}
int main() {
	cin >> n;
	vector<int>v;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == '1' && visited[i][j] == false)
				v.push_back(bfs(i, j));
		}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
}
