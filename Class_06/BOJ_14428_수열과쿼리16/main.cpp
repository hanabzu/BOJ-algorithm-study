/* BOJ_14428 수열과 쿼리 16 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 1987654321;
const int MAXN = 100000;
const int POWN = 18;
int N, M, B, q, x, y;

pair<int, int> idt[1 << POWN];

void update(int p, int c);

int get_min(int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(idt, idt + (1 << POWN), make_pair(INF,INF));

	cin >> N;

	for (B = 1; B < N; B <<= 1);

	for (int i = B; i < B + N; i++) {
		cin >> idt[i].first;
		idt[i].second = i - B + 1;
	}

	for (int i = B - 1; i > 0; i--) {
		idt[i] = min(idt[i << 1], idt[(i << 1) | 1]);
	}

	cin >> M;
	while (M--) {
		cin >> q;
		if (q == 1) {
			cin >> x >> y;
			update(x, y);
		}
		else {
			cin >> x >> y;
			cout << get_min(x, y) << '\n';
		}
	}

	return 0;
}


void update(int p, int c) {
	p += (B - 1);
	idt[p] = make_pair(c, p - B + 1);
	while (p >>= 1) {
		idt[p] = min(idt[p << 1], idt[(p << 1) | 1]);
	}
}

int get_min(int lhs, int rhs) {
	lhs += (B - 1);
	rhs += (B - 1);
	pair<int, int> s = make_pair(INF, INF);
	while (lhs <= rhs) {
		if ((lhs & 1) == 1) {
			s = min(s, idt[lhs]);
		}
		if ((rhs & 1) == 0) {
			s = min(s, idt[rhs]);
		}
		lhs = (lhs + 1) >> 1;
		rhs = (rhs - 1) >> 1;
	}
	return s.second;
}


