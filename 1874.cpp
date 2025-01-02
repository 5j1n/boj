#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	stack<int>s;
	vector<char>v;
	cin >> n;
	int idx = 1;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if ((!s.empty() && tmp > s.top()) || s.empty()) {
			while (idx <= tmp) {
				s.push(idx);
				idx++;
				v.push_back('+');
			}
		}
		if (!s.empty() && tmp == s.top())
		{
			s.pop();
			v.push_back('-');
		}
	}
	if (s.empty()) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << "\n";
	}
	else cout << "NO";
	
}
