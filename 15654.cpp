#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int>v;
bool used[10001];
int arr[9];

void tracking(int size) {
	if (size == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!used[v[i]]) {
			used[v[i]] = true;
			arr[size] = v[i];
			tracking(size + 1);
			used[v[i]] = false;
		}
	}

}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	tracking(0);
		
}
