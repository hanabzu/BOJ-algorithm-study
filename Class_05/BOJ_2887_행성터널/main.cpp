/* BOJ_2887 행성 터널 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

struct Star {
	int p, idx;
	Star(int p, int idx) :p(p), idx(idx) {}
	Star() {}
	bool operator<(const Star rhs) const {
		return this->p < rhs.p;
	}
};

struct Distance {
	int d, lhs, rhs;
	Distance(int d, int lhs, int rhs) :d(d), lhs(lhs), rhs(rhs) {}
	bool operator<(const Distance rhs) const {
		return this->d > rhs.d;
	}
	bool operator==(const Distance rhs) const {
		return (this->d == rhs.d) && (this->rhs == rhs.rhs) && (this->lhs == rhs.lhs);
	}
};

long long ans = 0;
int N, x, y, z;
Star X[MAXN], Y[MAXN], Z[MAXN];
priority_queue<Distance> q;
int parent[MAXN];

int find(int a);
void uni(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		parent[i] = i;
		cin >> x >> y >> z;
		X[i] = Star(x, i);
		Y[i] = Star(y, i);
		Z[i] = Star(z, i);
	}

	sort(X, X + N);
	sort(Y, Y + N);
	sort(Z, Z + N);

	for (int i = 1; i < N; i++) {
		q.push(Distance(X[i].p - X[i - 1].p, X[i - 1].idx, X[i].idx));
		q.push(Distance(Y[i].p - Y[i - 1].p, Y[i - 1].idx, Y[i].idx));
		q.push(Distance(Z[i].p - Z[i - 1].p, Z[i - 1].idx, Z[i].idx));
	}

	int n = 0;
	while (n < N - 1) {
		Distance D = q.top();
		q.pop();
		if (find(D.lhs) != find(D.rhs)) {
			uni(D.lhs, D.rhs);
			ans += D.d;
			n++;
		}
	}

	cout << ans;
	return 0;
}

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}

void uni(int a, int b) {
	parent[find(a)] = find(b);
}