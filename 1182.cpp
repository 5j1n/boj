#include <iostream>
using namespace std;

int a,b, arr[22], cnt;

void dfs(int k, int sum) {
	if (k == a) {
		if (sum == b)
			cnt++;
		return;
	}

	dfs(k + 1, sum);
	dfs(k + 1, sum + arr[k]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b;
	for (int i = 0; i < a; i++)
		cin >> arr[i];

	dfs(0, 0);

	if (b == 0)cout << cnt - 1;
	else cout << cnt;

}
