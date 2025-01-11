#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];
vector<int>v;
int main() {
	int n;
	stack<int>s;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.top() < arr[i])
		{
			v.push_back(s.top());
			s.pop();
		}
		if (s.empty() || s.top() > arr[i])
			s.push(arr[i]);
	}
	while (!s.empty()) {
		v.push_back(s.top());
		s.pop();
	}
	vector<int>v2 = v;
	sort(v2.begin(), v2.end());

	if (v2 == v) cout << "Nice";
	else cout << "Sad";
}
	
	
