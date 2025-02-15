#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;

int main() {
	while (1) {
		v.clear();
		for (int i = 0; i < 3; i++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		if (!v[0] && !v[1] && !v[2]) break;
		sort(v.begin(), v.end());
		if (v[2] >= v[1] + v[0]) cout << "Invalid\n";
		else {
			if (v[0] == v[1] && v[1]== v[2]) cout << "Equilateral\n";
			else if (v[0] == v[1] || v[1] == v[2]) cout << "Isosceles\n";
			else cout << "Scalene\n";
		}		
	}
}
