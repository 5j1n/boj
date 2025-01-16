#include <iostream>
#include <stack>
#include <vector>
#define ll long long 
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n;
	stack < pair < ll, ll >> s;
	
	cin >> n;
	vector <ll>v(n, -1);
	for (ll i = 0; i < n; i++) {
		ll tmp;	
		cin >> tmp;
		if (s.empty() || s.top().second > tmp) {
			s.push(make_pair(i,tmp));
		}
		else if (!s.empty() && s.top().second <= tmp) {
			while (!s.empty() && s.top().second < tmp) {
				v[s.top().first] = tmp;
				s.pop();
			}
			s.push(make_pair(i, tmp));
		}
	}
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	
}
