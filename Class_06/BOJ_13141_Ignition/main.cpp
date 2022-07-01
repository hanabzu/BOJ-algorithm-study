/* BOJ_13141 Ignition */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
const int MAXN = 200;
const int INF = 987654321;

int N, M, S, E, L;
float ans = INF;
int d[MAXN + 1][MAXN + 1], ld[MAXN + 1][MAXN + 1];

float get_longgest(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	fill(&d[0][0], &d[MAXN][MAXN + 1], INF);
	fill(&ld[0][0], &ld[MAXN][MAXN + 1], -INF);
	
	for (int i = 1; i <= N; i++) {
		d[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		cin >> S >> E >> L;
		if (d[S][E] > L) {
			d[S][E] = d[E][S] = L;
		}
		if (ld[S][E] < L) {
			ld[S][E] = ld[E][S] = L;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	
	for (int i = 1; i <= N; i++) {
		ans = min(ans, get_longgest(i));
	}

	cout << fixed;
	cout.precision(1);
	cout << ans;

	return 0;
}


float get_longgest(int n) {
	float t = 0;

	for (int s = 1; s <= N; s++) {
		for (int e = 1; e <= N; e++) {
			float long_edge = ld[s][e];

			if (ld[s][e] == -INF) continue; // no edge

			if (d[n][e] + long_edge < d[n][s]) continue; // already burned

			t = max(t, (long_edge + d[n][s] - d[n][e])/2 + d[n][e]);
		}
	}

	return t;
}
