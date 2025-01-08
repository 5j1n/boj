#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n;
	unordered_map<int, int>map;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		map[tmp]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		cout << map[tmp]<<" ";
	}
}
