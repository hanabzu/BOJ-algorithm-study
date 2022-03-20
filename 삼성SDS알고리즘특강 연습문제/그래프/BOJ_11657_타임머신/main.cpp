/* BOJ_11657 타임머신 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <limits.h>
#include <algorithm>
#define MAXN 500
using namespace std;

typedef tuple<int, int, int> TUP;

int N, M, A, B, C;
long long d[MAXN+1];
vector<TUP> e;

bool bellman();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		e.push_back(make_tuple(A, B, C));
	}

	fill(d, d + MAXN + 1, INT_MAX);
	d[1] = 0;


	if (bellman()) {
		for (int i = 2; i <= N; i++) {
			if (d[i] == INT_MAX) {
				cout << -1 << '\n';
			}
			else {
				cout << d[i] << '\n';
			}
		}
	}
	else {
		cout << -1;
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