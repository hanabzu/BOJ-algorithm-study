/* BOJ_2211 네트워크 복구 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
const int MAXN = 1000;
const int INF = 987654321;

int N, M, A, B, C, cost[MAXN + 1], parent[MAXN + 1];
vector<pii> e[MAXN + 1];

void dijkstra();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(cost, cost + MAXN + 1, INF);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		e[A].push_back(make_pair(C, B));
		e[B].push_back(make_pair(C, A));
	}

	dijkstra();

	cout << N - 1 << '\n';
	for (int i = 2; i <= N; i++) {
		cout << i << ' ' << parent[i] << '\n';
	}

	return 0;
}

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push(make_pair(0, 1));
	cost[1] = 0;

	while (!q.empty()) {
		int u = q.top().second;
		q.pop();

		for (int i = 0; i < e[u].size(); i++) {
			int nu = e[u][i].second;
			int nw = e[u][i].first;

			if (cost[nu] > cost[u] + nw) {
				cost[nu] = cost[u] + nw;
				parent[nu] = u;
				q.push(make_pair(cost[nw], nu));
			}
		}
	}
}
