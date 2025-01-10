#include <iostream>
#include <map>
using namespace std;

int main() {
	long long n, ans = 0, idx = 987654321, ret;
	cin >> n;
	map<long long, long long>map;

	for (long long i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		map[tmp]++;
	}
	
	for (auto it = map.begin(); it != map.end(); it++) {
		if (it->second > ans) {
			ans = it->second;
			idx = it->first;
			ret = idx;
		}
		else if (it->second == ans && it->first < idx) {
			idx = it->first;
			ret = idx;
		}
	}
	cout << ret;
}
