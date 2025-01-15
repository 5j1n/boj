#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int>v;
bool used[9];
int arr[9];
int printed[10001][9];
int idx;
void tracking(int size) {
	if (size == m) {
		bool flag = false;
		for (int i = 0; i <= idx; i++) {
			flag = false;
			for (int j = 0; j < m; j++) {
				if (printed[i][j] != arr[j]) {
					flag = true;
					break;
				}
			}
			if (flag) continue;
			else break;
		}
		if (flag) {
			for (int i = 0; i < m; i++) {
				cout << arr[i] << " ";
				printed[idx][i] = arr[i];
			}
			cout << "\n";
			idx++;
		}
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!used[i]&&arr[size-1]<=v[i]) {
			used[i] = true;
			arr[size] = v[i];
			tracking(size + 1);
			used[i] = false;
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
