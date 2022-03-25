/* BOJ_14503 로봇 청소기 */
/* hanabzu */

#include <iostream>

using namespace std;

enum {
	BLANK, WALL, CLEAN
};

const int MAXN = 50;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

int N, M, R, C, D, ans = 0;
int room[MAXN][MAXN];

bool move();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R >> C >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
		}
	}

	while (move());

	cout << ans;

	return 0;
}

bool move() {
	if (room[R][C] == BLANK) {
		ans++;
		room[R][C] = CLEAN;
	}

	int left = (D + 3) % 4;
	for (int i = 0; i < 4; i++) {
		int nr = R + dx[left];
		int nc = C + dy[left];

		if (room[nr][nc] != BLANK) {
			left = (left + 3) % 4;
			continue;
		}

		// have to clean
		R = nr;
		C = nc;
		D = left;
		return true;
	}

	// all 4 dir clean
	int nr = R - dx[D]; // go back
	int nc = C - dy[D];
	if (room[nr][nc] == WALL) {
		return false;
	}
	else {
		R = nr;
		C = nc;
		return true;
	}
}