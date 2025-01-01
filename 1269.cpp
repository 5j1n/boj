#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	int n, m;
	unordered_set<int>set;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int tmp;
		cin >> tmp;
		if (set.count(tmp) > 0) set.erase(tmp);
		else set.insert(tmp);
	}

	cout << set.size();
}
