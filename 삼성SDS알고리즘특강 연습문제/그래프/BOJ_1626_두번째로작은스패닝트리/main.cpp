/* BOJ_1626 두 번째로 작은 스패닝 트리 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1987654321;
const int MAXV = 50000;
const int MAXP = 17;

struct Edge {
	int a, b, cost;
	Edge(int a, int b, int c) : a(a), b(b), cost(c) {}
	bool operator<(const Edge another) const {
		return this->cost > another.cost;
	}
};

int V, E, a, b, c, num_e = 0;
int mst_parent[MAXV + 1];
priority_queue<Edge> e, unused;
vector<pii> mst[MAXV + 1];
bool visit[MAXV + 1];
int depth[MAXV + 1];
int parent[MAXP][MAXV + 1];
int maxw[MAXP][MAXV + 1];
int second_maxw[MAXP][MAXV + 1];
long long mst_cost = 0;
long long ans = LLONG_MAX;

void uni(int a, int b);
int find(int a);
void dfs(int p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	for (int i = 1; i <= V; i++) {
		mst_parent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		e.push(Edge(a, b, c));
	}

	while (!e.empty()) {
		Edge u = e.top();
		e.pop();
		if (find(u.a) != find(u.b)) {
			num_e++;
			mst_cost += u.cost;
			uni(u.a, u.b);
			mst[u.a].push_back(make_pair(u.b, u.cost));
			mst[u.b].push_back(make_pair(u.a, u.cost));
		}
		else {
			unused.push(u);
		}
	}

	if (num_e != V - 1 || unused.empty()) { // no MST
		cout << -1;
		return 0;
	}

	dfs(1); // make tree;

	for (int i = 0; i < MAXP - 1; i++) { // fill 2^i parent array
		for (int j = 1; j <= V; j++) {
			if (parent[i][j] != 0) {
				parent[i + 1][j] = parent[i][parent[i][j]];

				if (maxw[i][j] == maxw[i][parent[i][j]]) {
					maxw[i + 1][j] = maxw[i][j];
					second_maxw[i + 1][j] = max(second_maxw[i][j], second_maxw[i][parent[i][j]]);
				}
				else if (maxw[i][j] > maxw[i][parent[i][j]]) {
					maxw[i + 1][j] = maxw[i][j];
					second_maxw[i + 1][j] = max(second_maxw[i][j], maxw[i][parent[i][j]]);
				}
				else {
					maxw[i + 1][j] = maxw[i][parent[i][j]];
					second_maxw[i + 1][j] = max(second_maxw[i][parent[i][j]], maxw[i][j]);
				}
			}
		}
	}

	while (!unused.empty()) {
		Edge u = unused.top();
		unused.pop();
		if (depth[u.a] < depth[u.b]) swap(u.a, u.b);
		int diff_depth = depth[u.a] - depth[u.b];
		int mx = -INF;

		for (int j = 0; diff_depth; j++) {
			if (diff_depth & 1) {
				if (maxw[j][u.a] != u.cost) {
					mx = max(maxw[j][u.a], mx);
				}
				else if (second_maxw[j][u.a] != -INF) {
					mx = max(second_maxw[j][u.a], mx);
				}

				u.a = parent[j][u.a];
			}
			diff_depth >>= 1;
		}

		if (u.a != u.b) {
			for (int j = MAXP - 1; j >= 0; j--) {
				if (parent[j][u.a] != 0 && parent[j][u.a] != parent[j][u.b]) {
					if (maxw[j][u.a] != u.cost) {
						mx = max(maxw[j][u.a], mx);
					}
					else {
						mx = max(second_maxw[j][u.a], mx);
					}
					u.a = parent[j][u.a];
					if (maxw[j][u.b] != u.cost) {
						mx = max(maxw[j][u.b], mx);
					}
					else {
						mx = max(second_maxw[j][u.b], mx);
					}
					u.b = parent[j][u.b];
				}
			}
			if (maxw[0][u.a] != u.cost) {
				mx = max(maxw[0][u.a], mx);
			}
			else {
				mx = max(second_maxw[0][u.a], mx);
			}
			if (maxw[0][u.b] != u.cost) {
				mx = max(maxw[0][u.b], mx);
			}
			else {
				mx = max(second_maxw[0][u.b], mx);
			}
		}

		if (mx == -INF) {
			continue;
		}

		if (mx != u.cost) {
			ans = min(mst_cost - mx + u.cost, ans);
		}
	}

	if (ans == LLONG_MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}


	return 0;
}


void uni(int a, int b) {
	mst_parent[find(a)] = find(b);
}

int find(int a) {
	if (mst_parent[a] == a) {
		return a;
	}
	else {
		return mst_parent[a] = find(mst_parent[a]);
	}
}


void dfs(int p) {
	visit[p] = true;
	for (vector<pair<int, int>>::iterator it = mst[p].begin(); it != mst[p].end(); it++) {
		if (!visit[(*it).first]) {
			parent[0][(*it).first] = p;
			maxw[0][(*it).first] = (*it).second;
			second_maxw[0][(*it).first] = -INF;
			depth[(*it).first] = depth[p] + 1;
			dfs((*it).first);
		}
	}
}