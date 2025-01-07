#include <iostream>
#include <set>
using namespace std;



int main() {
	int t;
	cin >> t;
	while (t--) {
		multiset<int>set;
		int n;
		cin >> n;
		while (n--) {
			char command;
			int val;
			cin >> command >> val;
			if (command == 'I') set.insert(val);
			else {
				if (!set.empty()) {
					if (val == -1) set.erase(set.begin());
					else {
						auto it = set.end();
						it--;
						set.erase(it);
					}
				}
			}
		}

		if (set.empty()) cout << "EMPTY\n";
		else {
			auto it = set.end();
			it--;
			cout << *it << " ";
			it = set.begin();
			cout << *it<<"\n";
			
		}
	}
}

