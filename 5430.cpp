#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		string command;
		int n;
		bool flag = false, error = false;
		string str_list;
		cin >> command;
		cin >> n;
		cin >> str_list;
		deque<int>dq;
		int tmp = 0;
		for (int i = 0; i < str_list.size(); i++) {
			if (str_list[i] >= '0' && str_list[i] <= '9') {
				tmp = 10 * tmp + (str_list[i] - '0');
			}
			else if (str_list[i] == ','||str_list[i]==']') {
				if (str_list[i-1]!='[') dq.push_back(tmp);
				//cout << "tmp: " << tmp << "\n";
				tmp = 0;
			}
		}
		for (int i = 0; i < command.size(); i++) {
			if (command[i] == 'R') {
				if (!flag) flag = true;
				else flag = false;
			}
			else {
				if (!dq.empty())
				{
					if (flag) dq.pop_back();
					else dq.pop_front();
				}
				else {
					error = true;
					break;
				}
			}
		}
		if (error) cout << "error\n";
		else {
			cout << "[";
			if (!flag) {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];
					if (i < dq.size() - 1) cout << ",";
				}
			}
			else {
				for (int i = dq.size()-1; i>-1; i--){
					cout << dq[i];
					if (i > 0) cout << ",";
				}
			}
			cout << "]\n";
		}
	}
}
