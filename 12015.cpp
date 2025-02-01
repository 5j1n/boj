#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int>arr, stack;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		if (stack.size() == 0 || stack[stack.size() - 1] < arr[i])
			stack.push_back(arr[i]);
		else {
			int j = lower_bound(stack.begin(),stack.end(), arr[i])-stack.begin();
			stack[j] = arr[i];
		}
	}

	cout << stack.size();
}
