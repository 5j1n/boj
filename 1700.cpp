#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

int n, m, ans, plug[101], arr[101], item[101], num, idx;

int main() {
	cin >> n >> m;
	memset(item, -1, sizeof(item));
	for (int i = 0; i < m; i++)
		cin >> arr[i];
	for (int i = 0; i < m; i++) {
		if (num < n) {
			if (item[arr[i]] == -1) { // 해당 품목이 안꽂혀있고 비어있으면
				plug[idx] = arr[i];
				item[arr[i]] = idx;
				idx++;
				//cout << "비어있어서 " << arr[i] << "를 " << item[arr[i]] << "에 집어넣음\n";
				num++;
			}
			else {
			//	cout << "있음1\n";
			}
		}
		else {
			if (item[arr[i]] == -1) { // 해당 품목이 안꽂혀있고 안비어있으면
				vector<int>v;
				set<int>set;
				for (int j = i + 1; j < m; j++) {
					if (item[arr[j]] > -1 && set.count(arr[j]) == 0) {
						v.push_back(arr[j]);
						set.insert(arr[j]);
					}

					if (set.size() == n) { //set이 이미 꽉 찼으면 가장 나중에set 에 들어간 애와 교체
						plug[item[v[n - 1]]] = arr[i];
						item[arr[i]] = item[v[n - 1]];
						item[v[n - 1]] = -1;
						ans++;
						//cout << v[n - 1] << "과 " << arr[i] << "를 " << item[arr[i]] << "에서 교체1\n";
						break;
					}	
				}
				if (set.size() < n && set.size() > 0) {
					int target, target_idx;
					for (int i = 0; i < n; i++) {
						if (set.count(plug[i]) == 0) {
							target = plug[i];
							target_idx = i;
							break;
						}
					}
					plug[target_idx] = arr[i];
					item[arr[i]] = target_idx;
					item[target] = -1;
					ans++;
					//cout << target << "과 " << arr[i] << "를 " << item[arr[i]] << "에서 교체2\n";
				}
				else if (set.size() == 0) {
					plug[0] = arr[i];
					item[arr[i]] = 0;
					ans++;
					//cout << arr[i] << "를 " << item[arr[i]] << "에 걍 빼고 넣음\n";
				}
			}
			//else cout << "있음2\n";
		}

	}
	cout << ans;
}
