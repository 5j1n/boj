#include <iostream>
#include <stack>
#include <vector>
#define ll long long 
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n;
	stack<ll>s;
	cin >> n;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll tmp;	
		cin >> tmp;
		if (s.empty() || s.top() > tmp) {
			ans += s.size();
			s.push(tmp);
		}
		else if (!s.empty() && s.top() <= tmp) {
			while (!s.empty()&&s.top()<=tmp) s.pop();
			ans += s.size();
			s.push(tmp);
		}
	}
	cout << ans;
	
}
