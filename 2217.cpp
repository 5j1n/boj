#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001];
int main() {
	int n, maxi = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i<n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int tmp = (n - i) * v[i];
		if (maxi < tmp) maxi = tmp;
	}
	cout << maxi;
}
