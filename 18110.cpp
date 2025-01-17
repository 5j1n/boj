#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, cut, sum = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	cut = floor(double(n*0.15) + 0.5);
	for (int i = cut; i < n - cut; i++)
		sum += v[i];
	if (n == 0) {
		cout << 0;
		return 0;
	}
	cout << floor(double(sum) / double(n - 2 * cut) + 0.5);
}
