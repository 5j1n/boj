#include <iostream>
#include <deque>
using namespace std;

bool arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	deque<int>q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (arr[i]) continue;
		q.push_back(tmp);
	}

	int m;
	cin >> m;

	while (m--) {
		int tmp;
		cin >> tmp;
		q.push_front(tmp);
		cout << q.back() << " ";
		q.pop_back();
	}
}
