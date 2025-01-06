#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct birth {
	string name;
	int day;
	int month;
	int year;
};

bool compare(birth a, birth b) {
	if (a.year == b.year) {
		if (a.month == b.month)
			return a.day > b.day;
		return a.month > b.month;
	}
	return a.year > b.year;
}
int main() {
	int n;
	cin >> n;
	vector<birth>v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i].name >> v[i].day >> v[i].month >> v[i].year;

	sort(v.begin(), v.end(),compare);

	cout << v[0].name << "\n" << v[n - 1].name;
}
