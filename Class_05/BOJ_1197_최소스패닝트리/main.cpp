/* BOJ_1197 최소 스패닝 트리 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXV = 10000;

struct Edge {
	int a, b, cost;
	Edge(int a, int b, int c) : a(a), b(b), cost(c) {}
	bool operator<(const Edge another) const {
		return this->cost > another.cost;
	}
};

int V, E, A, B, C, num_e = 0, ans = 0;
priority_queue<Edge> e;
int parent[MAXV + 1];

void uni(int a, int b);
int find(int a);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		e.push(Edge(A, B, C));
	}

	while (num_e < V - 1) {
		Edge u = e.top();
		e.pop();
		if (find(u.a) != find(u.b)) {
			num_e++;
			ans += u.cost;
			uni(u.a, u.b);
		}
	}
	
	cout << ans;
	return 0;
}

void uni(int a, int b) {
	parent[find(a)] = find(b);
}

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}