#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	deque<int>q;
	int n, m, left, right, cnt = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		q.push_back(i);

	while (m--) {
		int num;
		cin >> num;

		for (int i = 0; i < q.size(); i++) {
			if (q[i] == num) {
				left = i;
				right = q.size() - i;
				break;
			}
		}
		if (left <= right) {
			while (1) {
				if (q.front() == num)
					break;

				q.push_back(q.front());
				q.pop_front();
				cnt++;
			}
			q.pop_front();
		}
		else {
			cnt++;
			while (1) {
				if (q.back() == num)
					break;

				q.push_front(q.back());
				q.pop_back();
				cnt++;
			}
			q.pop_back();
		}
	}

	cout << cnt;
}
