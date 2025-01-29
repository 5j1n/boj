#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int>v;
	cin >> n;
	int idx = 2;
	while(n>1) {
		while (n % idx == 0) {
			v.push_back(idx);
			n /= idx;
		}
		idx++;
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
}
