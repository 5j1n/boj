#include <iostream>
using namespace std;

int n, score, p,cnt,my=1;
int ran[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> score >> p;
	for (int i = 0; i < n; i++) {
		cin >> ran[i];
	}

	for (int i = 0; i < n; i++) {
		if (score < ran[i]) my += 1;
		else if (score > ran[i]) break;
		cnt++;
	}


	if (cnt == p) {
		cout << -1;
		return 0;
	}
	cout << my;
}
