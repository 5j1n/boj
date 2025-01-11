#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> obj[101];
int arr[101][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> obj[i].first >> obj[i].second;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			arr[i][j] = arr[i - 1][j];
			if (obj[i].first <= j)
				arr[i][j] = max(obj[i].second + arr[i - 1][j - obj[i].first], arr[i][j]);
		}
	}
	cout << arr[n][k];
}
