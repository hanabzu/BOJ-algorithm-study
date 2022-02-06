/* BOJ_1987 알파벳 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXR = 20;
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };
int R, C, ans = 0;
string board[MAXR];
bool visit[26];

void backtrack(int depth, int r, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}
	visit[board[0][0] - 'A'] = true;
	backtrack(1, 0, 0);
	cout << ans;
	return 0;
}

void backtrack(int depth, int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

		int c = board[nr][nc] - 'A';
		if (!visit[c]) {
			visit[c] = true;
			backtrack(depth + 1, nr, nc);
			visit[c] = false;
		}

	}

	if (depth > ans) {
		ans = depth;
	}
}