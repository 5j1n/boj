#include <iostream>
#include <vector>
using namespace std;

int arr[10000];
void post(int start, int end) {
	if (start >= end)
		return;
	if (start == end - 1) {
		cout << arr[start] << "\n";
		return;
	}
	int idx = start + 1;
	while (idx < end) {
		if (arr[start] < arr[idx])
			break;
		idx++;
	}

	post(start + 1, idx);
	post(idx, end);
	cout << arr[start] << "\n";
}

int main() {
	int num, idx;
	while (cin >> num) {
		arr[idx++] = num;
	}
	post(0, idx);
}
