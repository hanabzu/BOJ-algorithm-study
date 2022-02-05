/* BOJ_11779 최소비용 구하기 2 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits.h>
using namespace std;

const int MAXN = 1000;

int n, m, s, e, w;
vector<pair<int, int>> E[MAXN + 1];
int D[MAXN + 1];
int P[MAXN + 1];
vector<int> route;
void dijkstra();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> w;
		E[s].push_back(make_pair(w, e));
	}

	cin >> s >> e;
	dijkstra();

	cout << D[e] << '\n';
	int i = e;
	route.push_back(e);
	while (P[i] != s) {
		route.push_back(P[i]);
		i = P[i];
	}
	route.push_back(s);
	cout << route.size() << '\n';
	for (vector<int>::reverse_iterator it = route.rbegin(); it != route.rend(); it++) {
		cout << *it << ' ';
	}
	
	return 0;
}

void dijkstra() {
	priority_queue<pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> q;
	fill(D, D + n + 1, INT_MAX);
	D[s] = 0;
	q.push(make_pair(0, s));

	while (!q.empty()) {
		int u = q.top().second;
		int w = q.top().first;
		q.pop();
		
		if (D[u] < w) continue;

		for (vector<pair<int, int>>::iterator it = E[u].begin(); it != E[u].end(); it++) {
			int next_u = (*it).second;
			int next_w = (*it).first;

			if (D[next_u] > D[u] + next_w) {
				D[next_u] = D[u] + next_w;
				P[next_u] = u;
				q.push(make_pair(D[next_u], next_u));
			}
		}
	}

}