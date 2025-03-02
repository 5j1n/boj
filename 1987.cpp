#include <iostream>
#include <unordered_set>
#include <stack>

using namespace std;

char arr[21][21];
int visited[21][21];
bool used[27];
int n, m;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
unordered_set<char>set;

int dfs(int x, int y, int dist) {
    used[arr[x][y] - 'A'] = true;
    int maxDist = dist;  
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (used[arr[nx][ny]-'A']) continue;

        used[arr[nx][ny]-'A'] = true;

        maxDist = max(maxDist, dfs(nx, ny, dist + 1));

        used[arr[nx][ny]-'A'] = false;
    }

    return maxDist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	cout << dfs(0,0,1);

}
