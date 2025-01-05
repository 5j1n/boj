#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];
int cnt;

int main() {
	for (int i = 0; i < 4; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				if (!arr[i][j]) {
					arr[i][j] = 1;
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}
