/* hanabzu */
/* BOJ_1916 최소비용 구하기 */

#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

#define INT_MAX 200000000

int V, E, A, B, s_v, e_v, value;
int cost[1001] = { 0, };
vector<pair<int, int>> e[1001];

void dijkstra();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(cost, cost + 1001, INT_MAX);
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> s_v >> e_v >> value;
		e[s_v].push_back(make_pair(value, e_v));
	}

	cin >> A >> B;

	cost[A] = 0;
	dijkstra();
	cout << cost[B];
	return 0;
}


void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	q.push(make_pair(0, A));
	while (!q.empty()) {
		pair<int, int> u = q.top();
		q.pop();
		for (vector<pair<int, int>>::iterator it = e[u.second].begin(); it != e[u.second].end(); it++) {
			if (cost[(*it).second] > cost[u.second] + (*it).first) {
				cost[(*it).second] = cost[u.second] + (*it).first;
				q.push(make_pair(cost[(*it).second], (*it).second));
			}
		}
	}
}