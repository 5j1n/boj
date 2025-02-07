#include <iostream>
using namespace std;

int num[1000001];
int p[1000001];

int find(int x) {
	if (p[x] != x)return p[x] = find(p[x]);
	return p[x];
}

void uni(int a, int b){
	a = find(a);
	b = find(b);
	if (a > b) {
		p[a] = b;
		num[b]+=num[a];
	}
	else if (a < b) {
		p[b] = a;
		num[a]+=num[b];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i <= 1000000; i++) {
		p[i] = i;
		num[i] = 1;
	}
	int n;
	cin >> n;
	while (n--) {
		char command;
		cin >> command;
		if (command == 'I') {
			int a, b;
			cin >> a >> b;
			uni(a, b);
		}
		else {
			int a;
			cin >> a;
			cout << num[find(a)] << "\n";
		}
	}
}
