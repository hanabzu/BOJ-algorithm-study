/* BOJ_15481 그래프와 MST */
/* hanabzu */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits.h>

using namespace std;
typedef pair<int, int> pii;

const int MAXN = 200000, MAXM = 200000;
const int MAXP = 19;

struct Edge {
	int a, b, cost, idx;
	Edge() {}
	Edge(int a, int b, int c, int idx) :a(a), b(b), cost(c), idx(idx) {}
	bool operator<(const Edge another) const {
		return this->cost > another.cost;
	}
};

int N, M, u, v, w, num_e = 0;
int mst_parent[MAXN + 1];
priority_queue<Edge> pq;
Edge e[MAXM];
bool is_mst[MAXM];
vector<pii> mst[MAXN + 1];
bool visit[MAXN + 1];
int depth[MAXN + 1];
int parent[MAXP][MAXN + 1];
int maxw[MAXP][MAXN + 1];
long long mst_cost = 0;
long long ans = LLONG_MAX;

void LCA(int idx);
void uni(int a, int b);
int find(int a);
void dfs(int p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		mst_parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		cin >> e[i].a >> e[i].b >> e[i].cost;
		e[i].idx = i;
		pq.push(e[i]);
	}

	while (!pq.empty()) {
		Edge u = pq.top();
		pq.pop();
		if (find(u.a) != find(u.b)) {
			num_e++;
			mst_cost += u.cost;
			is_mst[u.idx] = true;
			uni(u.a, u.b);
			mst[u.a].push_back(make_pair(u.b, u.cost));
			mst[u.b].push_back(make_pair(u.a, u.cost));
		}
	}

	dfs(1); // make tree

	for (int i = 0; i < MAXP - 1; i++) {
		for (int j = 1; j <= N; j++) {
			if (parent[i][j] != 0) {
				parent[i + 1][j] = parent[i][parent[i][j]];
				maxw[i + 1][j] = max(maxw[i][j], maxw[i][parent[i][j]]);
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (is_mst[i]) {
			cout << mst_cost << '\n';
		}
		else {
			LCA(i);
		}
	}

	return 0;
}

void LCA(int idx) {
	int a = e[idx].a;
	int b = e[idx].b;
	int cost = e[idx].cost;

	if (depth[a] < depth[b]) swap(a, b);
	int diff_depth = depth[a] - depth[b];
	int MX = 0;

	for (int j = 0; diff_depth; j++) {
		if (diff_depth & 1) {
			if (maxw[j][a] != cost) {
				MX = max(maxw[j][a], MX);
			}
			a = parent[j][a];
		}
		diff_depth >>= 1;
	}

	if (a != b) {
		for (int j = MAXP - 1; j >= 0; j--) {
			if (parent[j][a] != 0 && parent[j][a] != parent[j][b]) {
				MX = max(maxw[j][a], MX);
				a = parent[j][a];
				MX = max(maxw[j][b], MX);
				b = parent[j][b];
			}
		}
		MX = max(maxw[0][a], MX);
		MX = max(maxw[0][b], MX);
	}

	cout << mst_cost - MX + cost << '\n';
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
	for (vector<pii>::iterator it = mst[p].begin(); it != mst[p].end(); it++) {
		int u = (*it).first;
		int cost = (*it).second;
		if (!visit[u]) {
			parent[0][u] = p;
			maxw[0][u] = cost;
			depth[u] = depth[p] + 1;
			dfs(u);
		}
	}
}