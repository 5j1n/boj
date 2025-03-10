#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

char arr[7][7];
bool visited[7][7], is_range[7][7];
vector<pair<int, int>>teacher, student, space;
int n, cnt;
bool ans;

bool tracking(int size) {
	if (size == 3) {
		cnt++;
		memset(is_range, false, sizeof(is_range));
		
		for (int i = 0; i < teacher.size(); i++) {
			int x = teacher[i].first;
			int y = teacher[i].second;

			for (int j = 0; j + x < n; j++) {
				int nx = j + x;
				if (arr[nx][y] != 'O')
					is_range[nx][y] = true;
				else break;
			}

			for (int j = 0; j + y < n; j++) {
				int ny = j + y;
				if (arr[x][ny] != 'O')
					is_range[x][ny] = true;
				else break;
			}

			for (int j = 0; x - j > -1; j++) {
				int nx = x - j;
				if (arr[nx][y] != 'O')
					is_range[nx][y] = true;
				else break;
			}

			for (int j = 0; y - j > -1; j++) {
				int ny = y - j;
				if (arr[x][ny] != 'O')
					is_range[x][ny] = true;
				else break;
			}
		}

		for (int i = 0; i < student.size(); i++) {
			int x = student[i].first;
			int y = student[i].second;

			if (is_range[x][y]) {
				return false;
			}
		}
		cout << "YES";
		ans = true;
		return true;
	}

	for (int i = 0; i < space.size(); i++) {
		if (ans == true) break;
		int x = space[i].first;
		int y = space[i].second;
		if (!visited[x][y]) {
			visited[x][y] = true;
			arr[x][y] = 'O';
			tracking(size + 1);
			visited[x][y] = false;
			arr[x][y] = 'X';
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S')
				student.push_back({ i,j });
			else if (arr[i][j] == 'T')
				teacher.push_back({ i,j });
			else space.push_back({ i,j });
		}
	}

	tracking(0);
	if (!ans) cout << "NO";
}
