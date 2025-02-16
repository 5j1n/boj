#include <iostream>
#include <queue>

using namespace std;

int arr[100001];

int main() {
	priority_queue<int>pq;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
		if (i == 0) {
			pq.push(arr[i]);
		}
		if (i == m - 1) {
			pq.push(n - arr[i]);
		}
		if (i > 0) {
			pq.push((arr[i] - arr[i - 1]+1) / 2);
		}
	} 
	cout << pq.top();
}
