/* BOJ_21609 상어 중학교 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

const int BLANK = -9;
const int MAXN = 20;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

int N, M, ans = 0;
int board[MAXN][MAXN], tmp[MAXN][MAXN];
bool visit[MAXN][MAXN];

int big_size, tmp_size, big_rbnum, tmp_rbnum, color;
pii big_head, tmp_head;

bool autoplay();
void dfs(pii p);
void del_dfs(pii p);
bool is_big();
void rotate();
void gravity();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	while (autoplay()) continue;

	cout << ans;
	return 0;
}

bool autoplay() {
	memset(visit, 0, sizeof visit);
	big_size = 0;
	big_rbnum = 0;
	big_head = make_pair(0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] || board[i][j] == 0 || board[i][j] == -1
				|| board[i][j] == BLANK) continue;

			visit[i][j] = true;
			tmp_size = 1;
			tmp_rbnum = 0;
			tmp_head = make_pair(i, j);
			color = board[i][j];
			
			dfs(tmp_head);

			if (tmp_size >= 2 && is_big()) {
				big_size = tmp_size;
				big_rbnum = tmp_rbnum;
				big_head = tmp_head;
			}

			for (int r = 0; r < N; r++) {
				for (int c = 0; c < N; c++) {
					if (board[r][c] == 0 && visit[r][c]) visit[r][c] = false;
				}
			}
		}
	}

	if (big_size == 0) return false;

	memset(visit, 0, sizeof visit);
	color = board[big_head.first][big_head.second];
	board[big_head.first][big_head.second] = BLANK;
	del_dfs(big_head);
	ans += (big_size * big_size);

	gravity();
	rotate();
	gravity();

	return true;
}


void dfs(pii p) {
	int r = p.first;
	int c = p.second;
	for (int d = 0; d < 4; d++) {
		int nr = r + dx[d];
		int nc = c + dy[d];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N || visit[nr][nc]) continue;

		if (board[nr][nc] == 0 || board[nr][nc] == color) {
			visit[nr][nc] = true;
			tmp_size++;
			if (board[nr][nc] == 0) tmp_rbnum++;
			dfs(make_pair(nr, nc));
		}
	}
}

void del_dfs(pii p) {
	int r = p.first;
	int c = p.second;
	for (int d = 0; d < 4; d++) {
		int nr = r + dx[d];
		int nc = c + dy[d];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N || visit[nr][nc]) continue;

		if (board[nr][nc] == 0 || board[nr][nc] == color) {
			visit[nr][nc] = true;
			board[nr][nc] = BLANK;
			del_dfs(make_pair(nr, nc));
		}
	}
}

bool is_big() {
	if (tmp_size > big_size) {
		return true;
	}
	else if (tmp_size == big_size) {
		if (tmp_rbnum > big_rbnum) {
			return true;
		}
		else if (tmp_rbnum == big_rbnum) {
			return tmp_head > big_head;
		}
	}
	return false;
}

void rotate() {
	memcpy(tmp, board, sizeof tmp);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = tmp[j][N - 1 - i];
		}
	}
}

void gravity() {
	for (int col = 0; col < N; col++) {
		for (int row = N - 2; row >= 0 ; row--) {
			if (board[row][col] == -1 || board[row][col] == BLANK) continue;

			int under = row + 1;
			while (under < N && board[under][col] == BLANK) {
				board[under][col] = board[under - 1][col];
				board[under - 1][col] = BLANK;
				under++;
			}
		}
	}
}