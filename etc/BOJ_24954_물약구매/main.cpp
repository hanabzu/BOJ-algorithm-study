/* BOJ_24954 물약 구매 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
const int MAXN = 11;
const int INF = 1987654321;
int N, n[MAXN], p, a, d, ans = INF;
vector<pair<int, int>> dc[MAXN];
bool visit[MAXN];

void dfs(int cost, int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> p;
		for (int j = 0; j < p; j++) {
			cin >> a >> d;
			dc[i].push_back(make_pair(a, d));
		}
	}

	dfs(0, 1);
	cout << ans;
	return 0;
}


void dfs(int cost, int num) {
	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;

		visit[i] = true;
		cost += max(n[i], 1);
		if (num == N) ans = min(ans, cost);
		for (vector <pair<int, int>>::iterator it = dc[i].begin(); it != dc[i].end(); it++) {
			n[(*it).first] -= (*it).second;
		}
		dfs(cost, num + 1);
		for (vector <pair<int, int>>::iterator it = dc[i].begin(); it != dc[i].end(); it++) {
			n[(*it).first] += (*it).second;
		}
		cost -= max(n[i], 1);
		visit[i] = false;
	}
}