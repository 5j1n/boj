#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int main()
{
	int n, ans = 0;
	
	cin >> n;
	vector<int>v1(n), v2(n);
	for (int i = 0; i < n; i++)
		cin >> v1[i];
	for (int i = 0; i < n; i++)
		cin >> v2[i];

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), compare);

	for (int i = 0; i < n; i++)
		ans += v1[i] * v2[i];
	cout << ans;
}
