#include <iostream>
#include <queue>
using namespace std;

priority_queue<int>maxHeap;
priority_queue<int, vector<int>, greater<int>>minHeap;
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, val;
	cin >> n;
	while (n--) {
		cin >> val;
		if (maxHeap.empty())
			maxHeap.push(val);

		else if (maxHeap.size() == minHeap.size())
			maxHeap.push(val);

		else
			minHeap.push(val);

		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
			int a = maxHeap.top();
			int b = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}

		cout << maxHeap.top() << "\n";
	}
}
