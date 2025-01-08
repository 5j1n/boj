#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string word, bomb;
	cin >> word >> bomb;

	stack<char>s,ans;
	for (int i = 0; i < word.length(); i++) {
		s.push(word[i]);
		
		if (s.top() == bomb[bomb.size() - 1] && s.size() >= bomb.length()) {
			string tmp;
			for (int i = 0; i < bomb.length(); i++) {
				tmp.push_back(s.top());
				s.pop();
			}
			reverse(tmp.begin(), tmp.end());
			if (bomb != tmp) {
				for (int i = 0; i < tmp.length(); i++)
					s.push(tmp[i]);
			}
		}
	}
	if (s.empty()) {
		cout << "FRULA";
		return 0;
	}
	while (!s.empty())
	{
		ans.push(s.top());
		s.pop();
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
}
