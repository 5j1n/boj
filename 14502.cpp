#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[9][9], visited[9][9];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
vector<pair<int, int>>emp;
queue <pair<int,int>>virus;
int n, m, ans, safe;

void change(pair<int, int>a, pair<int, int>b, pair<int, int>c) {
	arr[a.first][a.second] = 1;
	arr[b.first][b.second] = 1;
	arr[c.first][c.second] = 1;
}

void rechange(pair<int, int>a, pair<int, int>b, pair<int, int>c) {
	arr[a.first][a.second] = 0;
	arr[b.first][b.second] = 0;
	arr[c.first][c.second] = 0;
}

int dfs() {
	queue<pair<int, int>>q = virus;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visited[x][y] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx1 = x + dx[i];
			int nx2 = y + dy[i];
			if (nx1<1 || nx1>n || nx2<1 || nx2>m) continue;
			if (visited[nx1][nx2] == 0&&arr[nx1][nx2]==0) {
				visited[nx1][nx2] = 1;
				q.push({ nx1,nx2 });
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	ans = 0xfffffff;
	cin >> n >> m;
	for (int i =1; i<=n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
			{
				emp.push_back({ i,j });
				safe++;
			}
			else if (arr[i][j] == 2)
				virus.push({ i,j });
		}
	for (int i = 0; i < emp.size() - 2; i++)
		for (int j = i + 1; j < emp.size() - 1; j++)
			for (int k = j + 1; k < emp.size(); k++)
			{
				memset(visited, 0, sizeof(visited));
				change(emp[i], emp[j], emp[k]);
				int tmp = dfs();
				ans = min(tmp, ans);
				rechange(emp[i], emp[j], emp[k]);
			}
	cout << safe - ans - 3;
}
