#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#include <climits>
using namespace std;

int arr[51][51], origin[51][51];
bool visited[7];
int n, m, k, ans = INT_MAX;
int cnt;
deque<pair<int, pair<int, int>>>candi;
vector<pair<int, pair<int, int>>>v;

int circul() {
	for (int i = 0; i < k; i++) {
		int tmp_arr[51][51];
		memcpy(tmp_arr, arr, sizeof(arr));
		int r = candi[i].first;
		int c = candi[i].second.first;
		int s = candi[i].second.second;
		pair<int, int>st = { r - s,c - s };
		pair<int, int>en = { r + s,c + s };
		for (int j = 1; j <= s; j++) {
			for (int k = st.second + 1; k <= en.second; k++) {
				tmp_arr[st.first][k] = arr[st.first][k - 1];
			}
			for (int k = st.first + 1; k <= en.first; k++) {
				tmp_arr[k][en.second] = arr[k - 1][en.second];
			}
			for (int k = en.second - 1; k >= st.second; k--) {
				tmp_arr[en.first][k] = arr[en.first][k + 1];
			}
			for (int k = en.first - 1; k >= st.first; k--) {
				tmp_arr[k][st.second] = arr[k + 1][st.second];
			}
			st.first++; st.second++;
			en.first--; en.second--;
		}
		memcpy(arr, tmp_arr, sizeof(arr));
		
		/*cout << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}*/
	}
	int ret = INT_MAX;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			sum += arr[i][j];
		}
		if (sum < ret) ret = sum;
	}
	return ret;
}
void tracking(int size) {
	if (size == k) {
		memcpy(origin, arr, sizeof(origin));
		cnt++;
		int tmp = circul();
		ans = min(ans, tmp);
		memcpy(arr, origin, sizeof(arr));
		return;
	}

	for (int i = 0; i < k; i++) {
		if (!visited[i]) {
			visited[i] = true;
			candi.push_back(v[i]);
			tracking(size + 1);
			visited[i] = false;
			candi.pop_back();
		}
	}
	return;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,{b,c} });
	}

	tracking(0);
	//cout << cnt << "\n";
	cout << ans;
}
