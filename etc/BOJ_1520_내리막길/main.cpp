/* BOJ_1520 내리막 길 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 500;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

int M, N;
int map[MAXN][MAXN], dp[MAXN][MAXN];

int get_route(int r, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 1;
	cout << get_route(M - 1, N - 1);

	return 0;
}

int get_route(int r, int c) {
	if (dp[r][c] >= 0) return dp[r][c];

	dp[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];

		if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;

		if (map[r][c] >= map[nr][nc]) continue;

		dp[r][c] += get_route(nr, nc);
		
	}
	return dp[r][c];
}