#include <iostream>
#include <vector>
using namespace std;

int n, x, ans;
int arr[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		arr[v[i]]++;
	}
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (v[i] < x && x-v[i]< 1000001) {
			if (arr[x - v[i]] == 1) {
				ans++;
			}
		}
	}
	cout << ans/2;

}
