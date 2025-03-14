#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int arr[21][21], visited[21][21];
pair<int,int> babe;
int n, cnt, large, time;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
bool bfs() {
	queue<pair<int, int>>q;
	q.push(babe);
	memset(visited, -1, sizeof(visited));
	visited[babe.first][babe.second] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > n || ny > n || nx <= 0 || ny <= 0) continue;
			if (visited[nx][ny]!=-1||arr[nx][ny]>large) continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx,ny });

		}
	}
	vector<pair<int, int>>candidate;
	int dist = INT_MAX;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] > 0 && arr[i][j] < large) {
				if (visited[i][j] > 0 && dist > visited[i][j]) {
					dist = visited[i][j];
					candidate.clear();
					candidate.push_back({ i,j });
				}
				else if (dist == visited[i][j])
					candidate.push_back({ i,j });
			}
		}
	}

	sort(candidate.begin(), candidate.end(), cmp);
	if (!candidate.size()) return false;
	arr[babe.first][babe.second] = 0;
	babe = { candidate[0].first,candidate[0].second };
	arr[candidate[0].first][candidate[0].second] = 0;
	cnt++;
	if (cnt == large) {
		large++;
		cnt = 0;
	}
	time += dist;
	return true;

}
int main() {
	cin >> n;
	large = 2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
				babe = { i,j };
		}
	}
	while (1) {
		//cout << babe.first << " " << babe.second << "\n";
		if (!bfs())break;
	}
	cout << time;

}
