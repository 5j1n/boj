#include <iostream>

using namespace std;

int main() {
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;
	int ret = 1;
	if (c < a1||(c-a1)*n0<a0) ret = 0;
	cout << ret;
}
