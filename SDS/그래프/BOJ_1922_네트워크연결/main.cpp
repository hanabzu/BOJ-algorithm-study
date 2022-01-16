/* BOJ_1922 네트워크 연결 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#define MAXN 1000

using namespace std;
struct Edge {
	int a, b, cost;
	Edge(int a, int b, int c) : a(a), b(b), cost(c) {}
	bool operator<(const Edge another) const {
		return this->cost > another.cost;
	}
};
int N, M, a, b, c, num_e = 0, total = 0;
priority_queue<Edge> e;
int parent[MAXN + 1];

void union_find(int a, int b);
int find(int a);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a != b) {
			e.push(Edge(a, b, c));
		}
	}

	while (num_e < N-1) {
		Edge u = e.top();
		e.pop();
		if (find(u.a) != find(u.b)) {
			num_e++;
			total += u.cost;
			union_find(u.a, u.b);
		}
		
	}

	cout << total;
	return 0;
}

void union_find(int a, int b) {
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