#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
	string name;
	int kor;
	int eng;
	int math;
};

bool compare(student a, student b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				return a.name < b.name;
			}
			return a.math > b.math;
		}
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}

int main() {
	int n;
	cin >> n;

	vector<student>v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++)
		cout << v[i].name << "\n";
}
