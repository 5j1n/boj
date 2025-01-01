#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l;
vector<int>v;

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int ret = 1;
	int tmp = l - 1;

	for (int i = 0; i < n - 1; i++) {
		if (v[i + 1] - v[i] <= tmp) {
			tmp -= v[i + 1] - v[i];
		}
		else {
			tmp = l - 1;
			ret++;
		}
	}

	cout << ret;
}
