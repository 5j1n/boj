#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	stack<pair<int,int>>s;
	cin >> n;
	vector<int>v(n, 0);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (s.empty() || s.top().first < tmp) {
			while (!s.empty()&&s.top().first<tmp) s.pop();
			if (s.empty())v[i] = 0;
			else v[i] = s.top().second;
			s.push(make_pair(tmp,i+1));
		}
		else if (!s.empty() && s.top().first > tmp) {
			v[i] = s.top().second;
			s.push(make_pair(tmp,i+1));
		}
	}
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	
}
