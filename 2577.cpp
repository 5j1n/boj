#include <iostream>
#include <string>
using namespace std;
#define ll long long
	
int arr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;
	ll mult = a * b * c;
	string ans = to_string(mult);
	for (int i = 0; i < ans.size(); i++)
		arr[ans[i] - '0']++;
	for (int i = 0; i < 10; i++)
		cout << arr[i] << "\n";
}
