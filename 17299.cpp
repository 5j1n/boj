#include <iostream>
#include <stack>
using namespace std;

int arr[1000001], sum[1000001], ans[1000001];
pair<int, int>total[1000001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[arr[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		total[i].first = arr[i];
		total[i].second = sum[arr[i]];
	}

	stack<pair<int,int>>s;

	ans[n] = -1;
	s.push({ total[n].first,total[n].second });

	for (int i = n - 1; i >= 1; i--) {
		if (!s.empty()) {
			while (!s.empty()&&s.top().second <= total[i].second)
				s.pop();
			if (!s.empty()) ans[i] = s.top().first;
			else ans[i] = -1;
			s.push({ total[i].first,total[i].second });
		}
		else {
			ans[i] = -1;
			s.push({ total[i].first,total[i].second });
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
}
