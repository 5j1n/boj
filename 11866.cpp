#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n, m;
	vector<int>v;
	queue<int>q;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		for (int i = 1; i < m; i++) {
			q.push(q.front());
			q.pop();
		}
		v.push_back(q.front());
		q.pop();
	}
	cout << "<";
	for (int i = 0; i < v.size(); i++)
	{
		if (i == v.size() - 1)
			cout << v[i] << ">";
		else
			cout << v[i] << ", ";
	}

}
