#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n, d, k, c, ans = 0;
	map<int,int>map;
	cin >> n >> d >> k >> c;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		if (i < k) {
			map[tmp]++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (int(map.size()) >= ans) {
			ans = int(map.size());
			if (map.count(c) == 0) {
				ans++;		
			}
		}
		if (ans == k + 1) break;
		map[v[i]]--;
		if (map[v[i]] <= 0) map.erase(v[i]);
		map[v[(i + k)%n]]++;
	}
	cout << ans;
}
