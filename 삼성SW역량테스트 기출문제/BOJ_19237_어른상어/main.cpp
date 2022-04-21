/* BOJ_19237 어른 상어 */
/* hanabzu */

#include <iostream>
#include <string.h>

using namespace std;
struct Area {
	int own = 0, t = 0;
};

struct Shark {
	bool isOut = false;
	int r, c, d, dir[4][4];
};

const int MAXN = 20;
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };
int N, M, k, x, turn = 0, cnt = 0;
Area map[MAXN][MAXN];
bool visit[MAXN][MAXN];
Shark shark[MAXN * MAXN + 1];

bool move();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			if (x > 0) {
				shark[x].r = i;
				shark[x].c = j;
				map[i][j].own = x;
				map[i][j].t = k;
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> shark[i].d;
		shark[i].d--;
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int s = 0; s < 4; s++) {
				cin >> shark[i].dir[j][s];
				shark[i].dir[j][s]--;
			}
		}
	}

	while (move());

	cout << turn;
	return 0;
}

bool move() {
	if (turn++ >= 1000) {
		turn = -1;
		return false;
	}
	
	// sharks move
	for (int i = 1; i <= M; i++) {
		if (shark[i].isOut) continue;
		
		// no stink
		bool no_stink[4] = {0,}, my_stink[4] = {0,};
		int cnt_no_stink = 0, cnt_my_stink = 0;
		for (int j = 0; j < 4; j++) {
			int nr = shark[i].r + dx[shark[i].dir[shark[i].d][j]];
			int nc = shark[i].c + dy[shark[i].dir[shark[i].d][j]];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			if (map[nr][nc].own == 0) {
				no_stink[shark[i].dir[shark[i].d][j]] = true;
				cnt_no_stink++;
			}
			else if (map[nr][nc].own == i) {
				my_stink[shark[i].dir[shark[i].d][j]] = true;
				cnt_my_stink++;
			}
		}
		if (cnt_no_stink > 0) {
			for (int j = 0; j < 4; j++) {
				if (no_stink[shark[i].dir[shark[i].d][j]]) {
					shark[i].r += dx[shark[i].dir[shark[i].d][j]];
					shark[i].c += dy[shark[i].dir[shark[i].d][j]];
					shark[i].d = shark[i].dir[shark[i].d][j];
					break;
				}
			}
		}
		else { // go to my stink
			for (int j = 0; j < 4; j++) {
				if (my_stink[shark[i].dir[shark[i].d][j]]) {
					shark[i].r += dx[shark[i].dir[shark[i].d][j]];
					shark[i].c += dy[shark[i].dir[shark[i].d][j]];
					shark[i].d = shark[i].dir[shark[i].d][j];
					break;
				}
			}
		}
	}

	// sharks out
	for (int i = 1; i <= M; i++) {
		if (shark[i].isOut) continue;

		if (visit[shark[i].r][shark[i].c]) {
			shark[i].isOut = true;
			cnt++;
		}
		else {
			visit[shark[i].r][shark[i].c] = true;
		}
	}
	memset(visit, 0, sizeof visit);


	// stink shrink
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].own > 0) {
				if (--map[i][j].t == 0) {
					map[i][j].own = 0;
				}
			}
		}
	}

	// new stink
	for (int i = 1; i <= M; i++) {
		if (shark[i].isOut) continue;

		map[shark[i].r][shark[i].c].own = i;
		map[shark[i].r][shark[i].c].t = k;
	}


	if (cnt == M - 1) {
		return false;
	}
	return true;
}