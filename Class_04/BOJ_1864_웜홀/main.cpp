/* BOJ_1865 웜홀 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <limits.h>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> TUP;
const int MAXN = 500;

int TC, N, M, W, S, E, T;
int d[MAXN + 1];
vector<TUP> e;

bool bellman();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;
	while (TC--) {
		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			e.push_back(make_tuple(S, E, T));
			e.push_back(make_tuple(E, S, T));
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			e.push_back(make_tuple(S, E, -T));
		}

		if (!bellman()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

		e.clear();
	}

	return 0;
}

bool bellman() {
	int a, b, c;
	for (int i = 0; i < N; i++) {
		for (vector<TUP>::iterator it = e.begin(); it != e.end(); it++) {
			a = get<0>(*it); b = get<1>(*it); c = get<2>(*it);
			if (d[a] != INT_MAX && d[b] > d[a] + c) {
				d[b] = d[a] + c;
				if (i == N - 1) return false;
			}
		}
	}
	return true;
}