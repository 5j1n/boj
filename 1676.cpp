#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, num2 = 0, num5 = 0;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int tmp = i;
		while (tmp % 2 == 0) {
			num2++;
			tmp = tmp / 2;
		}
		while (tmp % 5 == 0) {
			num5++;
			tmp = tmp / 5;
		}
		
	}
	cout << min(num2, num5);
}
