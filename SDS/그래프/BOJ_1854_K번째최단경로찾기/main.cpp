/* BOJ_1854 K번째 최단경로 찾기 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

const int MAXN = 1000;

int N, M, K, a, b, c;
vector<pair<int, int>> e[MAXN + 1];
priority_queue<int> route[MAXN + 1];

void dijkstra();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		e[a].push_back(make_pair(c, b));
	}

	dijkstra();

	for (int i = 1; i <= N; i++) {
		if (route[i].size() < K ) {
			cout << "-1\n";
		}
		else {
			cout << route[i].top() << '\n';
		}
	}
	return 0;
}

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	q.push(make_pair(0, 1));
	route[1].push(0);

	while (!q.empty()) {
		int cost = q.top().first;
		int u = q.top().second;
		q.pop();
		for (vector<pair<int, int>>::iterator it = e[u].begin(); it != e[u].end(); it++) {
			int next = (*it).second;
			int new_cost = cost + (*it).first;

			if (route[next].size() < K) {
				q.push(make_pair(new_cost, next));
				route[next].push(new_cost);
			}
			else if (route[next].top() > new_cost) {
				q.push(make_pair(new_cost, next));
				route[next].pop();
				route[next].push(new_cost);
			}

		}
	}
}