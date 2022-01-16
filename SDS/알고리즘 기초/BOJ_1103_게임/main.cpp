/* BOJ_1103 ∞‘¿” */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N, M, max_depth = 0;
int dp[50][50];
int board[50][50];
bool visit[50][50];
string s;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void backtracking(int depth, pair<int,int> pos);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'H') {
				board[i][j] = 0;
			}
			else {
				board[i][j] = s[j] - '0';
			}
		}
	}

	backtracking(1, make_pair(0, 0));


	cout << max_depth;


	return 0;
}


void backtracking(int depth, pair<int, int> pos) {

	max_depth = max(depth, max_depth);

	dp[pos.first][pos.second] = depth;

	for (int i = 0; i < 4; i++) {
		int new_x = pos.first + dx[i] * board[pos.first][pos.second];
		int new_y = pos.second + dy[i] * board[pos.first][pos.second];

		if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M) {
			if (visit[new_x][new_y]) {
				cout << -1;
				exit(0);
			}
			if (dp[new_x][new_y] > 0 && depth < dp[new_x][new_y]) {
				continue;
			}

			if (board[new_x][new_y] != 0) {
				visit[new_x][new_y] = true;

				backtracking(depth + 1, make_pair(new_x, new_y));

				visit[new_x][new_y] = false;
			}
		}

	}

}