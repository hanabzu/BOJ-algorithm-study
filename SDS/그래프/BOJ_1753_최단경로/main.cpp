/* hanabzu */
/* BOJ_1753 최단 경로 */

#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

#define INT_MAX 2000000

int V, E, K, s_v, e_v, value;
int cost[20001] = { 0, };
vector<pair<int,int>> e[20001];

void dijkstra();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(cost, cost + 20001, INT_MAX);
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		cin >> s_v >> e_v >> value;
		e[s_v].push_back(make_pair(value, e_v));
	}

	cost[K] = 0;
	dijkstra();
	cost[K] = 0;
	for (int i = 1; i <= V; i++) {
		if (cost[i] == INT_MAX) {
			cout << "INF\n";
		}
		else {
			cout << cost[i] << '\n';
		}
	}
	return 0;
}


void dijkstra() {
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;

	q.push(make_pair(0, K));
	while (!q.empty()) {
		pair<int,int> u = q.top();
		q.pop();
		for (vector<pair<int, int>>::iterator it = e[u.second].begin(); it != e[u.second].end(); it++) {
			if (cost[(*it).second] > cost[u.second] + (*it).first) {
				cost[(*it).second] = cost[u.second] + (*it).first;
				q.push(make_pair(cost[(*it).second], (*it).second));
			}
		}
	}
}
