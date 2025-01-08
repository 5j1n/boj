#include <iostream>
using namespace std;

int arr[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string S;
	cin >> S;
	for (int i = 0; i < S.size(); i++)
		arr[S[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";
}
