#include <iostream>
#include <unordered_set>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

struct time {
	int hour = 0;
	int minute = 0;
};

void str_to_time(time &Time, string str) {
	//cout << str.size() << "\n";
	string tmp = str.substr(0, 2);
	Time.hour = stoi(tmp);
	tmp = str.substr(3, 5);
	Time.minute = stoi(tmp);

}
int main() {
	int ans = 0;
	unordered_set<string>set;
	string start, end, exit;
	cin >> start >> end >> exit;
	time Start,End, Exit;
	str_to_time(Start,start);
	str_to_time(End, end);
	str_to_time(Exit, exit);


	string str;
	cin.ignore();
	while (getline(cin, str)) {
		if (str == "\0") break;
		time chat;
		str_to_time(chat, str);
		string user = str.substr(6, str.size());
		if ((Start.hour == chat.hour && Start.minute >= chat.minute) || Start.hour > chat.hour) {
			set.insert(user);
			//cout << chat.hour << " " << chat.minute << " " << user << " 들어감\n";
		}
		else if ((End.hour == chat.hour && End.minute <= chat.minute) || End.hour < chat.hour) {
			if ((Exit.hour == chat.hour && Exit.minute >= chat.minute) || Exit.hour > chat.hour) {
				if (set.count(user)) {
					set.erase(user);
					//cout << chat.hour << " " << chat.minute << " " << user << " 나감\n";
					ans++;
				}
				
			}
		}
		
	}
	cout << ans;
}
