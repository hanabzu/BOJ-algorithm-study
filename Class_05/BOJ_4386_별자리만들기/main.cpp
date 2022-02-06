/* BOJ_4386 별자리 만들기 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAXN = 100;


int N, num_e = 0;
double x[MAXN + 1], y[MAXN + 1], ans = 0;

struct Edge {
	int a, b;
	double w = 0.0;
	Edge(int i, int j) :a(i), b(j) {
		w = sqrt(pow((x[i] - x[j]),2) + pow((y[i] - y[j]), 2));
	}

	bool operator<(const Edge& rhs) const {
		return this->w > rhs.w;
	}
};

priority_queue<Edge> e;
int parent[MAXN + 1];

void uni(int a, int b);
int find(int a);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			e.push(Edge(i, j));
			e.push(Edge(j, i));
		}
	}

	while (num_e < N - 1) {
		Edge u = e.top();
		e.pop();
		if (find(u.a) != find(u.b)) {
			num_e++;
			ans += u.w;
			uni(u.a, u.b);
		}
	}

	cout << fixed;
	cout.precision(2);
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