/* BOJ_1167 트리의 지름 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXV = 100000;

int V, v, u, w, maxw = 0, maxv;
vector<pair<int, int>> e[MAXV + 1];
bool visit[MAXV + 1];

void dfs(int v, int wsum);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;
	for (int i = 1; i <= V; i++) {
		cin >> v;
		while (1) {
			cin >> u;
			if (u == -1) break;
			cin >> w;
			e[v].push_back(make_pair(u, w));
		}
	}

	dfs(1, 0);

	dfs(maxv, 0);

	cout << maxw;

	return 0;
}

void dfs(int v, int wsum) {

	visit[v] = true;

	for (vector<pair<int, int>>::iterator it = e[v].begin(); it != e[v].end(); it++) {
		if (!visit[(*it).first]) {
			wsum += (*it).second;
			dfs((*it).first, wsum);
			wsum -= (*it).second;
		}
	}

	visit[v] = false;

	if (e[v].size() == 1) {
		if (wsum > maxw) {
			maxw = wsum;
			maxv = v;
		}
	}
}