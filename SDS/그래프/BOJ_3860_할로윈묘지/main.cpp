/* BOJ_3860 할로윈 묘지 */
/* hanabzu */

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string.h>
using namespace std;

typedef pair<int, int> pii;
typedef tuple<pii, pii, int> TUP;

enum {
	BLANK, RIP, GIN, END
};

const int MAXN = 30;
const int INF = 1987654321;
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };

int map[MAXN][MAXN];
int d[MAXN][MAXN];
int W, H, G, X, Y, E, X1, Y1, X2, Y2, T, N;

void testcase();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> W >> H;
		if (W == 0) break;
		testcase();
	}

	return 0;
}


void testcase() {
	memset(map, BLANK, sizeof(map));
	fill(&d[0][0], &d[MAXN - 1][MAXN], INF);

	vector<TUP> e;

	cin >> G;

	for (int i = 0; i < G; i++) {
		cin >> X >> Y;
		map[X][Y] = RIP;
	}

	cin >> E;
	for (int i = 0; i < E; i++) {
		cin >> X1 >> Y1 >> X2 >> Y2 >> T;
		e.push_back(make_tuple(make_pair(X1, Y1), make_pair(X2, Y2), T));
		map[X1][Y1] = GIN;
	}

	map[W - 1][H - 1] = END;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (map[i][j] == BLANK) {
				for (int d = 0; d < 4; d++) {
					int ni = i + dx[d];
					int nj = j + dy[d];
					if (ni < 0 || ni >= W || nj < 0 || nj >= H || map[ni][nj] == RIP) continue;
					e.push_back(make_tuple(make_pair(i, j), make_pair(ni, nj), 1));
				}
			}
		}
	}

	N = W * H - G; // num of nodes

	// bellman ford
	d[0][0] = 0;
	pii a, b;
	int c;
	for (int i = 0; i < N; i++) {
		for (vector<TUP>::iterator it = e.begin(); it != e.end(); it++) {
			a = get<0>(*it); b = get<1>(*it); c = get<2>(*it);
			if (d[a.first][a.second] != INF && d[b.first][b.second] > d[a.first][a.second] + c) {
				d[b.first][b.second] = d[a.first][a.second] + c;
				if (i == N - 1) {
					cout << "Never\n";
					return;
				}
			}
		}
	}

	if (d[W - 1][H - 1] == INF) {
		cout << "Impossible\n";
	}
	else {
		cout << d[W - 1][H - 1] << '\n';
	}
}