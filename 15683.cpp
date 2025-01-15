#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int arr[10][10], visited[10][10];
vector<int>v;
int m, n, ans=987654321, num = 1, tmp;
vector<pair<pair<int, int>, pair<int, int>>>vec;

void right(int x, int y) {
	while (y + 1 <= m && visited[x][y + 1] != 6) {
		if (visited[x][y+1]==0) visited[x][y + 1] = -1;
		y++;
	}
}
void left(int x, int y) {
	while (y - 1 > 0 && visited[x][y - 1] != 6) {
		if (visited[x][y - 1] == 0) visited[x][y - 1] = -1;
		y--;
	}
}

void up(int x, int y) {
	while (x - 1 > 0 && visited[x - 1][y] != 6) {
		if (visited[x - 1][y] ==0) visited[x - 1][y] = -1;
		x--;
	}
}

void down(int x, int y) {
	while (x + 1 <= n && visited[x + 1][y] != 6) {
		if (visited[x + 1][y] ==0) visited[x + 1][y] = -1;
		x++;
	}
}

void bfs() {
	{
		for (int i = 0; i < num; i++) {
			tmp = i;
			for (int j = v.size() - 1; j > -1; j--) {
				v[j] = tmp % 4;
				tmp = tmp / 4;
			}
			memcpy(visited, arr, sizeof(arr));
			for (int j = 0; j < v.size(); j++) {
				int turn = v[j];
				int cam = vec[j].first.second;
				int x = vec[j].second.first;
				int y = vec[j].second.second;

				if (cam == 1) {
					if (turn == 0) {
						right(x, y);
					}
					else if (turn == 1) {
						down(x, y);
					}
					else if (turn == 2) {
						left(x, y);
					}
					else {
						up(x, y);
					}
				
				}
				else if (cam == 2) {
					if (turn == 0 || turn == 2) {
						left(x, y);
						right(x, y);
					}
					else if (turn == 1 || turn == 3) {
						up(x, y);
						down(x, y);
					}
				}
				else if (cam == 3) {
					if (turn == 0) {
						right(x, y);
						down(x, y);
					}
					else if (turn == 1) {
						down(x, y);
						left(x, y);
					}
					else if (turn == 2) {
						left(x, y);
						up(x, y);
					}
					else {
						up(x, y);
						right(x, y);
					}
					
				}
				else if (cam == 4) {
					if (turn == 0) {
						right(x, y);
						left(x, y);
						down(x, y);
					}
					else if (turn == 1) {
						left(x, y);
						down(x, y);
						up(x, y);
					}
					else if (turn == 2) {
						down(x, y);
						up(x, y);
						right(x, y);
					}
					else {
						up(x, y);
						right(x, y);
						left(x, y);
					}
				}
				else {
					up(x, y);
					down(x, y);
					right(x, y);
					left(x, y);
				}
				int tmp_ans = 0;
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
					//	cout << visited[i][j] << " ";
						if (visited[i][j] == 0)
							tmp_ans++;
					}
				//	cout << "\n";
				}
			//	cout << "\n";
				ans = min(ans, tmp_ans);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	int idx = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				vec.push_back({ {idx, arr[i][j]},{i,j} });
				idx++;
			}
		}
	for (int i = 0; i < vec.size(); i++) {
		num *= 4;
	}

	v.resize(vec.size());
	bfs();
	int tmp_ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (visited[i][j] == 0)
				tmp_ans++;
	ans = min(ans, tmp_ans);
	cout << ans;

}
