#include <iostream>
#include <string>

using namespace std;

string wb[8] = { "WBWBWBWB","BWBWBWBW",
"WBWBWBWB","BWBWBWBW",
"WBWBWBWB","BWBWBWBW",
"WBWBWBWB","BWBWBWBW" };

string bw[8] = { "BWBWBWBW" , "WBWBWBWB",
"BWBWBWBW" , "WBWBWBWB",
"BWBWBWBW" , "WBWBWBWB",
"BWBWBWBW" , "WBWBWBWB" };
string board[50];

int wbCnt(int x, int y){
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[x + i][y + j] != wb[i][j])
				cnt++;
		}
	}
	return cnt;
}
int bwCnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[x + i][y + j] != bw[i][j])
				cnt++;
		}
	}
	return cnt;
}
int main() {
	int size[2], cnt, mini=0xfffffff;
	pair<int, int>p1;
	cin >> p1.first >> p1.second;
	for (int i = 0; i < p1.first; i++) {
		cin >> board[i];
	}
	for (int i = 0; i + 8 <= p1.first; i++)
	{
		for (int j = 0; j + 8 <= p1.second; j++)
		{
			int tmp;
			tmp = min(wbCnt(i, j), bwCnt(i, j));
			if (tmp < mini) {
				mini = tmp;
			}
		}
	}
	cout << mini;
}
