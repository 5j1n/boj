#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int>> arr;
int maxi = 0, maxi_idx;
int ans;

int main() {
	int n;
	cin >> n;
	arr.resize(n);
	stack<pair<int, int>>s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		maxi = max(maxi, arr[i].second);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		int loc = arr[i].first;
		int height = arr[i].second;
		if (s.empty()) s.push(arr[i]);
		else if (height > s.top().second) {
			//cout<< (loc - s.top().first) * s.top().second<<"\n";
			ans += (loc - s.top().first) * s.top().second;
			s.pop();
			s.push(arr[i]);
		}
		if (height == maxi) {
			//cout << height << "\n";
			ans += height;
			maxi_idx = i;
			break;
		}
	}
	while (!s.empty()) s.pop();

	for (int i = arr.size()-1; i > maxi_idx; i--) {
		int loc = arr[i].first;
		int height = arr[i].second;
		if (s.empty()) s.push(arr[i]);
		else if (height > s.top().second) {
			//cout << (s.top().first - loc) * s.top().second<<"\n";
			ans += (s.top().first - loc) * s.top().second;
			s.pop();
			s.push(arr[i]);
		}

		if (i == maxi_idx + 1) {
			//cout<< (s.top().first- arr[maxi_idx].first) <<" "<< s.top().second<<"\n";
			ans += (s.top().first - arr[maxi_idx].first) * s.top().second;
		}
	}
	cout << ans;
}
