/* BOJ_1516 게임 개발 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXV 500

using namespace std;
struct Node {
	int n, cost;
	Node(int n, int cost) : n(n), cost(cost) {}
	bool operator<(const Node a) const {
		return this->cost > a.cost;
	}
};

int N, cost, n;
int indegree[MAXV + 1];
int n_costs[MAXV + 1];
int total[MAXV + 1];
vector<int> v[MAXV + 1];
priority_queue<Node> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> n_costs[i];
		while (1) {
			cin >> n;
			if (n == -1) break;
			v[n].push_back(i);
			++indegree[i];
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (!indegree[i]) {
			q.push(Node(i, n_costs[i]));
		}
	}

	while (!q.empty()) {
		Node u = q.top();
		q.pop();
		total[u.n] += n_costs[u.n];
		for (vector<int>::iterator it = v[u.n].begin(); it != v[u.n].end(); ++it) {
			total[*it] = max(total[*it], total[u.n]);
			if (!(--indegree[*it])) {
				q.push(Node(*it, n_costs[*it]));
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << total[i] << '\n';
	}

	return 0;
}