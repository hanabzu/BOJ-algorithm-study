/* BOJ_17837 새로운 게임 2 */
/* hanabzu */

#include <iostream>
#include <string.h>

using namespace std;
enum {
	WHITE, RED, BLUE
};
const int MAXTURN = 1000;
const int MAXN = 12;
const int MAXK = 10;
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { 1,-1,0,0 };

struct Piece {
	Piece** pnum;
	int r = -1, c = -1, d = -1, h = -1;
};

int N, K, board[MAXN][MAXN], row, col, dir, turn = 0;
Piece piece[MAXN][MAXN][10];
Piece* k[MAXK];
int psize[MAXN][MAXN];

bool move(Piece* p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> row >> col >> dir;
		row--; col--; dir--;
		k[i] = &piece[row][col][0];
		psize[row][col] = 1;
		piece[row][col][0].pnum = &k[i];
		piece[row][col][0].r = row;
		piece[row][col][0].c = col;
		piece[row][col][0].d = dir;
		piece[row][col][0].h = 0;
	}

	while (turn++ <= MAXTURN) {
		for (int i = 0; i < K; i++) {
			if (!move(k[i])) {
				cout << turn;
				return 0;
			}
		}
	}

	cout << ((turn <= MAXTURN) ? turn : -1);
	return 0;
}

bool move(Piece* p) {
	int r = p->r;
	int c = p->c;
	int d = p->d;
	int nr = r + dx[d];
	int nc = c + dy[d];

	if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == BLUE) {
		d = p->d = (d < 2) ? (d + 1) % 2 : 2 + (d + 1) % 2;
		nr = r + dx[d];
		nc = c + dy[d];
	}

	if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == BLUE) { // don't move
		return true;
	}

	int pcount = psize[r][c] - p->h;
	int h = p->h, dh = 1;
	if (board[nr][nc] == RED) {
		h = psize[r][c] - 1;
		dh = -1;
	}

	psize[r][c] -= pcount;
	while (pcount--) {
		piece[nr][nc][psize[nr][nc]].r = nr;
		piece[nr][nc][psize[nr][nc]].c = nc;
		piece[nr][nc][psize[nr][nc]].d = piece[r][c][h].d;
		piece[nr][nc][psize[nr][nc]].h = psize[nr][nc];
		piece[nr][nc][psize[nr][nc]].pnum = piece[r][c][h].pnum;
		*(piece[nr][nc][psize[nr][nc]].pnum) = &piece[nr][nc][psize[nr][nc]];

		psize[nr][nc]++;
		h += dh;
	}


	return (psize[nr][nc] < 4);
}