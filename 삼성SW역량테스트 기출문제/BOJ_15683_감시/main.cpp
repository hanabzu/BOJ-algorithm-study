/* BOJ_15683 감시 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
const int MAXN = 8;
const int INF = 1000;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

struct CCTV {
	int x, y, t, d = 0;
	CCTV() {}
	CCTV(int x, int y, int t) : x(x), y(y), t(t) {}
};

int N, M, room[MAXN][MAXN], tmp[MAXN][MAXN], K = 0, ans = INF;
CCTV cctv[8];

void dfs(int p);
void look(int r, int c, int d);
int count();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
			if (room[i][j] != 0 && room[i][j] != 6) {
				cctv[K++] = CCTV(i, j, room[i][j]);
			}
		}
	}
	dfs(0);
	cout << ans;

	return 0;
}

void dfs(int p) {
	if (p == K) {
		ans = min(ans, count());
		return;
	}

	if (cctv[p].t == 5) {
		dfs(p + 1);
	}
	else if (cctv[p].t == 2) {
		for (int i = 0; i < 2; i++) {
			cctv[p].d = i;
			dfs(p + 1);
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			cctv[p].d = i;
			dfs(p + 1);
		}
	}
}

void look(int r, int c, int d) {
	while (true) {
		r += dx[d];
		c += dy[d];

		if (r < 0 || r >= N || c < 0 || c >= M || tmp[r][c] == 6) return;

		tmp[r][c] = -1; // look
	}
}

int count() {
	int cnt = 0;
	memcpy(tmp, room, sizeof(room));
	for (int i = 0; i < K; i++) {
		if (cctv[i].t == 1) {
			look(cctv[i].x, cctv[i].y, cctv[i].d);
		}
		else if (cctv[i].t == 2) {
			look(cctv[i].x, cctv[i].y, cctv[i].d);
			look(cctv[i].x, cctv[i].y, (cctv[i].d + 2) % 4);
		}
		else if (cctv[i].t == 3) {
			look(cctv[i].x, cctv[i].y, cctv[i].d);
			look(cctv[i].x, cctv[i].y, (cctv[i].d + 1) % 4);
		}
		else if (cctv[i].t == 4) {
			look(cctv[i].x, cctv[i].y, cctv[i].d);
			look(cctv[i].x, cctv[i].y, (cctv[i].d + 1) % 4);
			look(cctv[i].x, cctv[i].y, (cctv[i].d + 2) % 4);
		}
		else { // cctv[i].t == 5
			for (int j = 0; j < 4; j++) {
				look(cctv[i].x, cctv[i].y, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}