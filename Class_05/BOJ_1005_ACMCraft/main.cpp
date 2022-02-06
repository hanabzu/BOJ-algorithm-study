/* BOJ_1005 ACM Craft */
/* hanabzu */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct Node {
	int n, cost;
	Node(int n, int cost) : n(n), cost(cost) {}
	bool operator<(const Node a) const {
		return this->cost > a.cost;
	}
};

const int MAXN = 1000;
int T, N, K, X, Y, W;
int w[MAXN + 1];
int indegree[MAXN + 1];
int total[MAXN + 1];

void solution();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		solution();
	}

	return 0;
}

void solution() {
	vector<int> v[MAXN + 1];
	priority_queue<Node> q;
	int ans = 0;
	cin >> N >> K;
	fill(total, total + N + 1, 0);
	fill(indegree, indegree + N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < K; i++) {
		cin >> X >> Y;
		v[X].push_back(Y);
		indegree[Y]++;
	}

	cin >> W;
	for (int i = 1; i <= N; ++i) {
		if (!indegree[i]) {
			q.push(Node(i, w[i]));
		}
	}

	while (!q.empty()) {
		Node u = q.top();
		q.pop();
		total[u.n] += w[u.n];
		for (vector<int>::iterator it = v[u.n].begin(); it != v[u.n].end(); ++it) {
			total[*it] = max(total[*it], total[u.n]);
			if (!(--indegree[*it])) {
				q.push(Node(*it,w[*it]));
			}
		}
	}

	cout << total[W] << '\n';
}