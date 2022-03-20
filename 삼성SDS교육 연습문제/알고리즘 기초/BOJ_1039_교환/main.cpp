/* BOJ_1039 교환 */
/* hanabzu */

#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

queue<string> q;

string N, ans = "0";
int K, q_size;
void bfs();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	q.push(N);

	while(K--){
		bfs();
	}

	while (!q.empty()) {
		ans = max(ans, q.front());
		q.pop();
	}

	if (ans[0] == '0') cout << -1;
	else cout << ans;

	return 0;
}


void bfs() {
	set<string> s;
	q_size = q.size();

	for (int k = 0; k < q_size; k++) {
		string str = q.front();
		q.pop();
		if (s.count(str)) continue;
		s.insert(str);
		for (int i = 0; i < str.size() - 1; i++) {
			for (int j = i + 1; j < str.size(); j++) {
				if (i != 0 || str[j] != '0') {
					swap(str[i], str[j]);

					q.push(str);

					swap(str[i], str[j]);
				}
			}
		}
	}
}
