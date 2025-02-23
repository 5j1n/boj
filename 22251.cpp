	#include <iostream>

	using namespace std;
	int n, k, p, x, ans;

	bool arr[10][7] = { {1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{0,1,1,1,1,0,1},{0,1,1,1,0,1,1},{1,0,1,1,0,1,0},{1,1,0,1,0,1,1},
		{1,1,0,1,1,1,1},{0,1,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1} };

	int main() {
		ios::sync_with_stdio(false);
		cin.tie(0); cout.tie(0);

		cin >> n >> k >> p >> x;
		for (int i = 1; i <= n; i++) {
			if (i == x) continue;
			int original = x;
			int changed = i;

			int cnt = 0;
			for (int j = 0; j < k; j++) {
				for (int z = 0; z < 7; z++) {
					if (arr[original % 10][z] != arr[changed % 10][z]) cnt++;
				}
				original /= 10;
				changed /= 10;
			}
			if (cnt <= p) ans++;
		}
		cout << ans;
	}
