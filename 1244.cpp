#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector<int>v(n + 1, -1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int gender, button;
		cin >> gender >> button;
		if (gender == 1) {
			for (int i = 1; i <= n; i++)
			{
				if (i % button == 0) {
					if (v[i]) v[i] = 0;
					else v[i] = 1;
				}
			}
		}
		else {
			int left = button, right = button;
			while (left>0&&right<=n&&v[left] == v[right]) {
				if (v[left]==1&&v[right]==1) {
					v[left] = 0;
					v[right] = 0;
				}
				else if (v[left] == 0 && v[right] == 0) {
					v[left] = 1;
					v[right] = 1;
				}
				left--;
				right++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		
		cout << v[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
}
