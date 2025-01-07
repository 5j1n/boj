#include <iostream>
#include <deque>
using namespace std;

pair<int, int>arr[50];
int ra;
int main() {
	int n;
	cin >> n;
	for (int i =0; i<n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
				ra++;
			
		}
		cout << ra + 1 << " ";
		ra = 0;
	}
}
