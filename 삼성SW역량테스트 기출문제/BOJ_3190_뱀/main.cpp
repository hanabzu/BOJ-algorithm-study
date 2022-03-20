/* BOJ_3190 뱀 */
/* hanabzu */

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

enum {
	BLANK, SNAKE, APPLE
};
const int MAXN = 100;
const int dx[4] = { 0,-1,0,1 };
const int dy[4] = { 1,0,-1,0 };

int N, K, row, col, L, dir = 0, ans = 0, L_idx = 0;
queue<pair<int, int>> q;
int board[MAXN][MAXN];
pair<int, char> L_info[MAXN];
bool move();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	board[0][0] = SNAKE;
	q.push(make_pair(0, 0));

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> row >> col;
		board[row - 1][col - 1] = APPLE;
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> L_info[i].first >> L_info[i].second;
	}

	while (move());

	cout << ans;
	return 0;
}

bool move() {
	// time goes
	ans++;

	// new head
	int n_row = q.back().first + dx[dir];
	int n_col = q.back().second + dy[dir];

	// stuck condition
	if (n_row < 0 || n_row >= N || n_col < 0 || n_col >= N 
		|| board[n_row][n_col] == SNAKE) {
		return false;
	}

	// no apple
	if (board[n_row][n_col] == BLANK) {
		board[q.front().first][q.front().second] = BLANK;
		q.pop();
	}
	
	// push to queue
	board[n_row][n_col] = SNAKE;
	q.push(make_pair(n_row, n_col));

	// change direction
	if (ans == L_info[L_idx].first) {
		if (L_info[L_idx].second == 'L') dir = (dir + 1) % 4;
		else dir = (dir + 3) % 4;
		L_idx++;
	}
	return true;
}