#include <iostream>
using namespace std;

int arr[5][5];
pair<int, int>num[26];

bool func() {
	int finish = 0;
	int cross1 = 0, cross2 = 0;
	for (int i = 0; i < 5; i++) {
		int col = 0, row = 0;

		for (int j = 0; j < 5; j++) {
			if (!arr[i][j]) row++;
			if (!arr[j][i]) col++;
		}

		if (col == 5) finish++;
		if (row == 5) finish++;
		if (!arr[i][i]) cross1++;
		if (!arr[i][4 - i]) cross2++;
	}

	if (cross1 == 5) finish++;
	if (cross2 == 5) finish++;
	if (finish > 2) return true;

	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i<5; i++)
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
			num[arr[i][j]] = { i,j };
		}

	int ans = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			ans++;
			int tmp;
			cin >> tmp;
			arr[num[tmp].first][num[tmp].second] = 0;

			if (i > 1) {
				if (func()) {
					cout << ans;
					return 0;
				}
			}
		}
	}
}
