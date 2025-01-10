#include <iostream>
#include <set>

using namespace std;

int arr[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	set<int>set;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "add")
		{
			int x;
			cin >> x;
			arr[x] = 1;
		}
		else if (command == "remove") {
			int x;
			cin >> x;
			arr[x] = 0;
		}
		else if (command == "check") {
			int x;
			cin >> x;
			cout << arr[x] << "\n";
		}
		else if (command == "toggle") {
			int x;
			cin >> x;
			if (arr[x] == 0) arr[x] = 1;
			else arr[x] = 0;
		}
		else if (command == "all") {
			for (int i = 1; i <= 20; i++)
				arr[i] = 1;	
		}
		else
			for (int i = 1; i <= 20; i++)
				arr[i] = 0;
			
	}
}
