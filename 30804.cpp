#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	int cnt = 0;
	cin >> n;
	vector<int>v(n);
	vector<int>arr(10);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int st = 0, en = 0;
	int i = 0;
	while (en < n) {
		arr[v[en]]++;
		if (arr[v[en]] == 1) cnt++;
		en++;
		
		while (cnt > 2) {
			arr[v[st]]--;
			if (arr[v[st]] == 0) {
				cnt--;
				//cout << "I removed " << v[st] << " at "<<i<<"\n";
				//if (cnt <= 2) break;
			}
			st++;
			
		}
		//cout << st << "\n";
		res = max(res, en - st);
		i++;
	}

	cout << res;
}
