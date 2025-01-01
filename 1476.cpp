#include <iostream>
using namespace std;

int main() {
	int e, s, m;
	cin >> e >> s >> m;

	for (int i = 1;; i++) {
		int a = i % 15;
		if (!a) a = 15;
		int b = i % 28;
		if (!b) b = 28;
		int c = i % 19;
		if (!c) c = 19;
		if (a == e &&b == s && c == m) {
			cout << i;
			return 0;
		}
	}
}
