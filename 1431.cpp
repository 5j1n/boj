#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		int tmp1 = 0, tmp2 = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] >= '0' && a[i] <= '9')
				tmp1 += a[i] - '0';
			if (b[i] >= '0' && b[i] <= '9')
				tmp2 += b[i] - '0';
		}

		if (tmp1 == tmp2) return a < b;

		return tmp1 < tmp2;
	}

	return a.length() < b.length();
}

int main() {
	int n;
	cin >> n;
	vector<string>v(n);
	for (int i = 0; i<n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++)
		cout << v[i] << "\n";
}
