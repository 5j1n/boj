#include <iostream>

using namespace std;

char arr[1001][1001];

int n;
pair<int, int>heart;
int left_arm, right_arm, whrist, left_leg, right_leg, whrist_y;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '*' && heart.first == 0) {
				heart.first = i + 1;
				heart.second = j;
			}
		}

	for (int i = 1; i < heart.second; i++) {
		if (arr[heart.first][i] == '*')
			left_arm++;
	}
	for (int i = heart.second + 1; i <= n; i++) {
		if (arr[heart.first][i] == '*')
			right_arm++;
		else break;
	}
	for (int i = heart.first + 1; i <= n; i++) {
		if (arr[i][heart.second] == '*')
			whrist++;
		else {
			whrist_y = i - 1;
			break;
		}
	}
	for (int i = whrist_y + 1; i <= n; i++) {
		if (arr[i][heart.second-1] == '*')
			left_leg++;
		else {
			break;
		}
	}
	for (int i = whrist_y + 1; i <= n; i++) {
		if (arr[i][heart.second + 1] == '*')
			right_leg++;
		else {
			break;
		}
	}
	cout << heart.first << " " << heart.second << "\n";
	cout << left_arm << " " << right_arm <<" "<< whrist << " " << left_leg << " " << right_leg << "\n";
}
