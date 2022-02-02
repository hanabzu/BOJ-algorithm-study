/* BOJ_1504 특정한 최단 경로 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 800;
const int MAXE = 200000;
const int INF = 98765432;
vector<pair<int, int>> e[MAXN + 1];
int d[MAXN + 1];
int N, E, a, b, c, v1, v2;

void dijkstra(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		e[a].push_back(make_pair(c, b));
		e[b].push_back(make_pair(c, a));
	}

	cin >> v1 >> v2;
	
	dijkstra(1);
	int res1 = d[v1];
	int res2 = d[v2];
	dijkstra(v1);
	res1 += d[v2];
	res2 += d[N];
	dijkstra(v2);
	res1 += d[N];
	res2 += d[v1];

	if (res1 >= INF && res2 >= INF) {
		cout << -1;
	}
	else {
		cout << min(res1, res2);
	}
	return 0;
}

void dijkstra(int v){
	bool visit[MAXN + 1] = { 0, };

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	fill(d, d + MAXN + 1, INF);
	d[v] = 0;
	q.push(make_pair(0, v));

	while (!q.empty()) {
		pair<int, int> u = q.top();
		q.pop();
		if (visit[u.second]) continue;
		visit[u.second] = true;
		for (vector<pair<int, int>>::iterator it = e[u.second].begin(); it != e[u.second].end(); it++) {
			if (d[(*it).second] > d[u.second] + (*it).first) {
				d[(*it).second] = d[u.second] + (*it).first;
				q.push(make_pair(d[(*it).second], (*it).second));
			}
		}
	}
}