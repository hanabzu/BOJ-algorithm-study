/* BOJ_12094 2048 (hard) */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

enum {
	LEFT, RIGHT, UP, DOWN
};

const int MAXN = 20;
const int MAX_DEPTH = 10;
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };

int board[MAXN][MAXN];
bool visit[MAXN][MAXN];
int dp[MAX_DEPTH][MAXN][MAXN];
int req_local_max[MAX_DEPTH + 1];
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
			ans = max(ans, board[i][j]);
		}
	}

	dfs(0);

	cout << ans;

	return 0;
}

void dfs(int depth) {
	int local_max = 0;
	for (int i = 0; i < N; i++) {
		local_max = max(local_max, *max_element(board[i], board[i] + N));
	}
	if (local_max <= req_local_max[depth]) return;

	if (depth == MAX_DEPTH) {
		ans = max(ans, local_max);

		int min_val = ans;

		while (depth > 0) {
			req_local_max[depth--] = min_val;
			min_val >>= 1;
		}
		return;
	}

	memcpy( dp[depth], board, sizeof(board));

	//copy_board(board, dp[depth]);

	for (int i = 0; i < 4; i++) {
		if (slide(depth, i)) {
			dfs(depth + 1);
			//copy_board(dp[depth], board);
			memcpy(board, dp[depth], sizeof(board));
		}
	}
}

bool slide(int depth, int dir) {
	memset(visit, 0, sizeof(visit));

	if (dir == 0) {
		for (int r = 0; r < N; r++) {
			for (int c = 1; c < N; c++) {
				int tc = c;
				if (board[r][tc] == 0) continue;
				
				while (board[r][tc - 1] == 0 && tc > 0) {
					board[r][tc - 1] = board[r][tc];
					board[r][tc] = 0;
					tc--;
				}

				if (tc == 0) continue;

				if (!visit[r][tc - 1] && board[r][tc] == board[r][tc - 1]) {
					board[r][tc] = 0;
					board[r][tc - 1] <<= 1;
					visit[r][tc - 1] = 1;
				}

			}
		}
	}
	else if (dir == 1) {
		for (int r = 0; r < N; r++) {
			for (int c = N - 2; c >= 0; c--) {
				int tc = c;
				if (board[r][tc] == 0) continue;

				while (board[r][tc + 1] == 0 && tc < N - 1) {
					board[r][tc + 1] = board[r][tc];
					board[r][tc] = 0;
					tc++;
				}

				if (tc == N - 1) continue;

				if (!visit[r][tc + 1] && board[r][tc] == board[r][tc + 1]) {
					board[r][tc] = 0;
					board[r][tc + 1] <<= 1;
					visit[r][tc + 1] = 1;
				}

			}
		}
	}
	else if (dir == 2) {
		for (int c = 0; c < N; c++) {
			for (int r = 1; r < N; r++) {
				int tr = r;
				if (board[tr][c] == 0) continue;

				while (board[tr - 1][c] == 0 && tr > 0) {
					board[tr - 1][c] = board[tr][c];
					board[tr][c] = 0;
					tr--;
				}

				if (tr == 0) continue;

				if (!visit[tr - 1][c] && board[tr][c] == board[tr - 1][c]) {
					board[tr][c] = 0;
					board[tr - 1][c] <<= 1;
					visit[tr - 1][c] = 1;
				}
			}
		}
	}
	else { // dir == 3
		for (int c = 0; c < N; c++) {
			for (int r = N - 2; r >= 0; r--) {
				int tr = r;
				if (board[tr][c] == 0) continue;

				while (board[tr + 1][c] == 0 && tr < N - 1) {
					board[tr + 1][c] = board[tr][c];
					board[tr][c] = 0;
					tr++;
				}

				if (tr == N - 1) continue;

				if (!visit[tr + 1][c] && board[tr][c] == board[tr + 1][c]) {
					board[tr][c] = 0;
					board[tr + 1][c] <<= 1;
					visit[tr + 1][c] = 1;
				}
			}
		}
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