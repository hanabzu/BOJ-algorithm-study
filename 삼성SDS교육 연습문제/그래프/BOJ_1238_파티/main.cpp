/* BOJ_1238 파티 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
#include <algorithm>
#define MAXN 1000
using namespace std;

int result[MAXN + 1];
int d[MAXN + 1];
vector<pair<int, int>> e[MAXN + 1], re[MAXN + 1];

int N, M, X, a, b, t, answer = 0;
void dijkstra(int V, vector<pair<int,int>> (&E)[MAXN+1]);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> X;

	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> t;
		e[a].push_back(make_pair(t, b));
		re[b].push_back(make_pair(t, a));
	}

	// X to every nodes
	dijkstra(X, e);
	for (int i = 1; i <= N; i++) {
		result[i] = d[i];
	}

	// Every nodes to X
	dijkstra(X, re);
	for (int i = 1; i <= N; i++) {
		result[i] += d[i];
	}

	cout << *max_element(result, result + MAXN+1);
	return 0;
}

void dijkstra(int V, vector<pair<int, int>>(&E)[MAXN + 1]) {
	bool visit[MAXN + 1] = { 0, };
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	fill(d, d + MAXN + 1, INT_MAX);
	d[V] = 0;
	q.push(make_pair(0, V));

	while (!q.empty()) {
		pair<int, int> u = q.top();
		q.pop();
		if (visit[u.second]) continue;
		visit[u.second] = true;
		for (vector<pair<int, int>>::iterator it = E[u.second].begin(); it != E[u.second].end(); it++) {
			if (d[(*it).second] > d[u.second] + (*it).first) {
				d[(*it).second] = d[u.second] + (*it).first;
				q.push(make_pair(d[(*it).second], (*it).second));
			}
		}
	}
}