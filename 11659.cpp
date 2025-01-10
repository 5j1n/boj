#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100001], sum[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> a >> b;

	for (int i = 1; i <= a; i++)
		cin >> arr[i];
	sum[1] = arr[1];

	for (int i = 2; i <= a; i++) {
		sum[i] = arr[i] + sum[i - 1];
	}

	for (int i = 0; i < b; i++) {
		int x, y;
		cin >> x >> y;
		cout << sum[y] - sum[x-1]<<"\n";
	}
}
