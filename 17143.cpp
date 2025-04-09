#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Shark {
	int r;
	int c;
	int s;
	int d;
	bool alive = true;
};

int dx[] = {0, -1,1,0,0 };
int dy[] = {0, 0,0,1,-1 };

int score, r, c, m, cnt;
vector<Shark>shark;
int arr[101][101];

void fishing(int loc) {
	int idx = 1; 
	while (idx <= r) {
		if (arr[idx][loc]) {
			shark[arr[idx][loc]].alive = false;
			cnt--;
			score += arr[idx][loc];
			arr[idx][loc] = 0;
			return;
		}
		idx++;
	}
}

void move() {
	int tmp[101][101];
	memset(tmp, 0, sizeof(tmp));

	for (int i = 1; i <= 10000; i++) {
		if (shark[i].alive) {
			if (shark[i].r == 1 && shark[i].d == 1) shark[i].d = 2;
			else if (shark[i].r == r && shark[i].d == 2) shark[i].d = 1;
			else if (shark[i].c == 1 && shark[i].d == 4) shark[i].d = 3;
			else if (shark[i].c == c && shark[i].d == 3) shark[i].d = 4;
			vector<pair<int, int>>rule;
			if (shark[i].d == 1 || shark[i].d == 2) {
				rule.assign(2 * r - 1, { 0,0 });
				int nx = shark[i].r;
				for (int j = 1; j <= 2 * (r-1); j++) {
					nx += dx[shark[i].d];
					if (nx == 1 && shark[i].d == 1) shark[i].d = 2;
					else if (nx == r && shark[i].d == 2) shark[i].d = 1;
					rule[j] = { nx,shark[i].d };
				}
				int tmp = 0;
				if (shark[i].s % (2 * (r - 1)) == 0) tmp = 2 * r - 2;
				else tmp = shark[i].s % (2 * r - 2);
				shark[i].d = rule[tmp].second;
				shark[i].r = rule[tmp].first;
			}
			else if (shark[i].d==3 || shark[i].d==4) {
				rule.assign(2 * c - 1, {0,0});
				int ny = shark[i].c;
				int ny2 = ny;
				for (int j = 1; j <= 2 * c -2; j++) {
					ny2 += dy[shark[i].d];
					if (ny2 == 1 && shark[i].d == 4) shark[i].d = 3;
					else if (ny2 == c && shark[i].d == 3) shark[i].d = 4;
					rule[j] = { ny2,shark[i].d };
				}
				int tmp = 0;
				if (shark[i].s % (2 * c -2) == 0) tmp = 2 * c -2;
				else tmp = shark[i].s % (2 * c- 2);
				shark[i].d = rule[tmp].second;
				shark[i].c = rule[tmp].first;
			}

			if (tmp[shark[i].r][shark[i].c]) {
				shark[tmp[shark[i].r][shark[i].c]].alive = false;
				cnt--;
			}
			tmp[shark[i].r][shark[i].c] = i;
		}
	}

	memcpy(arr, tmp, sizeof(arr));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> r >> c >> m;
	shark.assign(10001, {0,0,0,0,false});

	for (int i = 0; i < m; i++) {
		Shark tmp;
		int size;
		cin >> tmp.r >> tmp.c >> tmp.s >> tmp.d >> size;
		shark[size] = tmp;
		arr[tmp.r][tmp.c] = size;
		cnt++;
	}

	for (int i = 1; i <= c; i++) {
		if (!cnt) break;
		fishing(i);
		move();
	}
	cout << score;
}
