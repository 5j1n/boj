#include <iostream>
#include <unordered_set>
using namespace std;

int cnt[201][201];
char arr[201][201];
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
unordered_set<int>set;

int main() {
	int r, c, n;
	cin >> r >> c >> n;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'O') {
				cnt[i][j] = 2;
			}
			else cnt[i][j] = -1;
		}
	}
	int sec = 2;

	while (sec <= n) {
		if (sec % 2 == 0) {
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++) {
					if (arr[i][j] == '.') {
						arr[i][j] = 'O';
						cnt[i][j] = 0;
					}
				}
			}
		}
		else {
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++) {
					if (arr[i][j] == 'O' && cnt[i][j] == 3) {
						for (int k = 0; k < 5; k++) {
							int n = i + dx[k];
							int m = j + dy[k];
							if (n < 0 || m < 0 || n >= r || m >= c) continue;
							if (arr[n][m] == 'O') {
								set.insert(n * 201 + m);
							}
						}
					}
				}
			}
			for (auto it = set.begin(); it != set.end(); it++) {
				int tmp = *it;
				int m = tmp % 201;
				tmp /= 201;
				int n = tmp;
				arr[n][m] = '.';
				cnt[n][m] = -1;
			}
			set.clear();
		}
		sec++;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 'O') cnt[i][j]++;
			}
		}

	}


	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}



}
