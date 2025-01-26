#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
	vector<long long>v;
	long long n;
	cin >> n;
	while (n--) {
		long long tmp, tmp2 = 0;
		cin >> tmp;
		while (tmp > 0) {
			tmp2 = 10 * tmp2;
			tmp2 += tmp % 10;
			tmp /= 10;
		}
		v.push_back(tmp2);
		
	}
	sort(v.begin(), v.end());

	for (long long i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	
}
