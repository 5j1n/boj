#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<int>set;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		set.insert(tmp);
	}
	for (auto it = set.begin(); it != set.end(); it++) {
		cout << *it << " ";
	}
}
