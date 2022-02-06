/* BOJ_1761 정점들의 거리 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int MAXN = 40000;
const int MAXP = 16;

struct Edge {
	int node, w;
	Edge(int node, int w) : node(node), w(w) {}
	Edge() {}
};

vector<Edge> e[MAXN + 1];
bool visit[MAXN + 1];
int depth[MAXN + 1];
int weight[MAXN + 1];
int parent[MAXP][MAXN + 1];
int N, M, a, b, c, ans;

void dfs(int p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		e[a].push_back(Edge(b, c));
		e[b].push_back(Edge(a, c));
	}

	dfs(1); // make tree

	for (int i = 0; i < MAXP - 1; i++) { // fill 2^i parent array
		for (int j = 1; j <= N; j++) {
			if (parent[i][j] != 0) {
				parent[i + 1][j] = parent[i][parent[i][j]];
			}
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		ans = weight[a] + weight[b];

		if (depth[a] < depth[b]) swap(a, b); // a's depth > b's depth

		int diff_depth = depth[a] - depth[b];

		for (int i = 0; diff_depth; i++) { // move a to same depth with b
			if (diff_depth & 1) {
				a = parent[i][a];
			}
			diff_depth >>= 1;
		}
		if (a != b) {
			for (int i = MAXP - 1; i >= 0; i--) {
				if (parent[i][a] != 0 && parent[i][a] != parent[i][b]) {
					a = parent[i][a];
					b = parent[i][b];
				}
			}
			a = parent[0][a];
		}

		ans -= ((weight[a]) << 1);
		cout << ans << '\n';
	}

	return 0;
}

void dfs(int p) {
	visit[p] = true;
	for (vector<Edge>::iterator it = e[p].begin(); it != e[p].end(); it++) {
		int next = (*it).node;
		int w = (*it).w;
		if (!visit[next]) {
			parent[0][next] = p;
			weight[next] = weight[p] + w;
			depth[next] = depth[p] + 1;
			dfs(next);
		}
	}
}