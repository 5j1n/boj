#include <iostream>
#include <stack>
#include <set>
#include <cmath>
#include <climits>

using namespace std;

int arr[100001];
int myL[100001], myR[100001], cnt[100001];
stack<pair<int, int>>l, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long n;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (long long i = n - 1; i > -1; i--) {
		long long cur = arr[i];
		while (!r.empty() && r.top().first <= arr[i]) {
			r.pop();
		}
		if (!r.empty()) myR[i] = r.top().second;
		cnt[i] += r.size();
		r.push({ arr[i], i + 1 });
	}

	for (long long i = 0; i < n; i++) {
		long long cur = arr[i];
		while (!l.empty() && l.top().first <= arr[i]) {
			l.pop();
		}
		if (!l.empty()) myL[i] = l.top().second;
		cnt[i] += l.size();
		l.push({ arr[i],i + 1 });
	}

	for (long long i = 0; i < n; i++) {
		cout << cnt[i] << " ";
		if (myR[i] != 0 && myL[i] == 0)
			cout << myR[i] << "\n";
		else if (myR[i] == 0 && myL[i] != 0)
			cout << myL[i] << "\n";
		else if (myR[i] != 0 && myL[i] != 0) {
			if (abs(myR[i] - (i + 1)) == abs(myL[i] - (i + 1)))
				cout << myL[i] << "\n";
			else if (abs(myR[i] - (i + 1)) > abs(myL[i] - (i + 1)))
				cout << myL[i] << "\n";
			else cout << myR[i] << "\n";
		}
		else cout << "\n";
	}
}
