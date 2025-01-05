#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque <char>q;

int main() {
	int n, k;
	string str;
	cin >> n >> k >> str;

	for (int i = 0; i < str.length(); i++) {
		while (k && !q.empty() && q.back() < str[i]) {
			q.pop_back();
			k--;
		}
		q.push_back(str[i]);
	}

	for (int i = 0; i < q.size() - k; i++)
		cout << q[i];
}
