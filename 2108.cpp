#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 0xfffffff
using namespace std;

int main() {
	int n, maxi = -INF, mini = INF, most = 0, mostVal = INF, num = 0;
	int ans[4] = { 0, };
	unordered_map<int, int>map;
	vector<int>v;
	vector<int>freq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > maxi) maxi = tmp;
		if (tmp < mini) mini = tmp;
		map[tmp]++;
		if (map[tmp] > most) {
			most = map[tmp];
			freq.clear();
			freq.push_back(tmp);
		}
		else if (map[tmp] == most)
			freq.push_back(tmp);
		v.push_back(tmp);
		ans[0] += tmp;
	}
	//cout << double(ans[0]) / double(n) << "\n";
	//cout << int(ans[0] / n) << "\n";
	if (abs(double(ans[0]) / double(n) - int(ans[0] / n)) >= 0.5)
	{
		if (ans[0] / n < 0) ans[0] = ans[0] / n - 1;
		else ans[0] = ans[0] / n + 1;
	}
	else
		ans[0] = ans[0] / n;
	sort(v.begin(), v.end());

	
	ans[1] = v[n / 2];
	sort(freq.begin(), freq.end());
	if (freq.size() > 1)
		ans[2] = freq[1];
	else
		ans[2] = freq[0];
	ans[3] = maxi - mini;
	for (int i = 0; i < 4; i++)
		cout << ans[i] << "\n";

}
