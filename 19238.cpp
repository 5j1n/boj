#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct G {
	int sX;
	int sY;
	int eX;
	int eY;
};

pair<int, int>taxi;
vector<G>guest;
int fuel, n, m;
int arr[21][21];
int visited[21][21];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


bool cmp(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b) {
	if (a.first == b.first) {
		if (a.second.first == b.second.first) {
			return a.second.second < b.second.second;
		}
		return a.second.first < b.second.first;
	}
	return a.first < b.first;

}

pair<int,int> bfs() {
	vector < pair<int, pair<int, int>>>v;
	queue<pair<int, int>>q;
	q.push(taxi);
	visited[taxi.first][taxi.second] = 0;
	if (arr[taxi.first][taxi.second] == 2) {
		v.push_back({ visited[taxi.first][taxi.second], { taxi } });
	}
	if (!v.size()) {
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<1 || ny<1 || nx>n || ny>n) continue;
				if (visited[nx][ny] != -1) continue;
				if (arr[nx][ny] == 1) continue;
				visited[nx][ny] = visited[x][y] + 1;
				q.push({ nx,ny });
				if (arr[nx][ny] == 2) {
					v.push_back({ visited[nx][ny], {nx,ny} });
				}
			}
		}
	}

	if (v.size() == 0) return { -1,-1 };
	sort(v.begin(), v.end(), cmp);
	return v[0].second;
}

int destination(pair<int, int>loc) {
	queue<pair<int, int>>q;
	q.push(taxi);
	visited[taxi.first][taxi.second] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>n) continue;
			if (visited[nx][ny] != -1) continue;
			if (arr[nx][ny] == 1) continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx,ny });
			if (nx == loc.first && ny == loc.second) return visited[nx][ny];
		}
	}
	return -1;
}

int go(pair<int, int>loc) {
	if (loc.first == -1) return -1;

	if (fuel - visited[loc.first][loc.second] >= 0) {
		fuel -= visited[loc.first][loc.second];
		taxi = loc;
	}
	else return -1;

	for (int i = 0; i < guest.size(); i++) {
		if (guest[i].sX == loc.first && guest[i].sY == loc.second) {
			memset(visited, -1, sizeof(visited));
			int tmp = destination({ guest[i].eX, guest[i].eY});
			if (tmp == -1) return -1;
			else if (fuel - tmp < 0) return -1;
			else {
				fuel += tmp;
				taxi = { guest[i].eX,guest[i].eY };
				
				arr[guest[i].sX][guest[i].sY] = 0;
				guest.erase(guest.begin() + i);
				return 0;
			}
		}
	}
}
int main() {
	cin >> n >> m >> fuel;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> taxi.first >> taxi.second;

	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		guest.push_back({ a,b,c,d });
		arr[a][b] = 2;
	}

	while (fuel > 0 && guest.size()) {
		memset(visited, -1, sizeof(visited));
		int tmp = go(bfs());
		if (tmp == -1) {
			cout << -1;
			return 0;
		}
	}
	if (fuel > 0) cout << fuel;
	else cout << -1;
}
