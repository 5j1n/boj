#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int i = 1;
	while (n > i) {
		n = n - i;
		i++;
	}

	if (i % 2 == 0)
		cout << n << "/" << i + 1 - n << "\n";
	else
		cout << i + 1 - n << "/" << n << "\n";
}
