/* BOJ_12100 2048 (Easy) */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

enum {
	LEFT, RIGHT, UP, DOWN
};

const int MAXN = 21;
const int MAX_DEPTH = 5;
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };

int board[MAXN][MAXN];
bool visit[MAXN][MAXN];
int dp[MAX_DEPTH][MAXN][MAXN];
int N, ans = 0;

void dfs(int depth);
bool slide(int depth, int dir);
void copy_board(int A[][MAXN], int B[][MAXN]);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0);

	cout << ans;

	return 0;
}

void dfs(int depth) {

	for (int i = 0; i < N; i++) {
		ans = max(ans, *max_element(board[i], board[i] + N));
	}
	if (depth == MAX_DEPTH) {
		return;
	}

	copy_board(board, dp[depth]);
	
	for (int i = 0; i < 4; i++) {
		if (slide(depth, i)) {
			dfs(depth + 1);
			copy_board(dp[depth], board);
		}
		
	}
}

bool slide(int depth, int dir) {

	for (int i = 0; i < N; i++) {
		fill(visit[i], visit[i] + N, false);
	}
	
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (dir == UP || dir == DOWN) {
				swap(r, c);
			}
			if (dir == RIGHT) {
				c = N - c - 1;
			}
			if (dir == DOWN) {
				r = N - r - 1;
			}
			
			int tr = -1, tc = -1;
			if (board[r][c] > 0) {
				for (tr = r + dx[dir], tc = c + dy[dir]; tr < N && tc < N && tr >= 0 && tc >= 0; tr += dx[dir], tc += dy[dir]) {
					if (board[tr][tc] == 0) {
						continue;
					}

					if (!visit[tr][tc] && board[r][c] == board[tr][tc]) {
						board[r][c] = 0;
						board[tr][tc] <<= 1;
						visit[tr][tc] = 1;
					}
					break;
				}

				
				if (board[r][c] > 0) {
					int nr = r + dx[dir];
					int nc = c + dy[dir];
					while (nr < N && nc < N && nr >= 0 && nc >= 0 && board[nr][nc] == 0) { // push
						board[nr][nc] = board[nr - dx[dir]][nc - dy[dir]];
						board[nr - dx[dir]][nc - dy[dir]] = 0;
						nr += dx[dir];
						nc += dy[dir];
					}
				}


				while (tr < N && tc < N && tr >= 0 && tc >= 0 && board[tr][tc] == 0) { // push
					board[tr][tc] = board[tr - dx[dir]][tc - dy[dir]];
					board[tr - dx[dir]][tc - dy[dir]] = 0;
					visit[tr][tc] = visit[tr - dx[dir]][tc - dy[dir]];
					visit[tr - dx[dir]][tc - dy[dir]] = 0;
					tr += dx[dir];
					tc += dy[dir];
				}

			}

			if (dir == RIGHT) {
				c = N - c - 1;
			}
			if (dir == DOWN) {
				r = N - r - 1;
			}
			if (dir == UP || dir == DOWN) {
				swap(r, c);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		ans = max(ans, *max_element(board[i], board[i] + N));
	}
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[depth][i][j] != board[i][j]) {
				return true;
			}
		}
	}

	return false;
}


void copy_board(int A[][MAXN], int B[][MAXN]) {
	for (int i = 0; i < N; i++) {
		copy(A[i], A[i] + N, B[i]);
	}
}