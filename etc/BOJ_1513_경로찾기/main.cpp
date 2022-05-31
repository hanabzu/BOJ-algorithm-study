/* BOJ_1513 경로 찾기 */
/* hanthird */

#include <iostream>
#include <utility>
using namespace std;

const int MAXN = 51;
const int MOD = 1000007;

int N, M, C, x, y;
int game[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN]; // r, c, cnt, last_idx

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> C;
	for (int i = 1; i <= C; i++) {
		cin >> x >> y;
		game[x][y] = i;
	}

	dp[1][1][(game[1][1] > 0 ? 1 : 0)][game[1][1]] = 1;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			for (int i = 0; i <= C; i++) {
				for (int j = 0; j <= C; j++) {
					if (dp[r][c][i][j] == 0) continue;


					if (r + 1 <= N) {
						if (game[r + 1][c] == 0) {
							dp[r + 1][c][i][j] += dp[r][c][i][j];
							dp[r + 1][c][i][j] %= MOD;
						}
						else if (game[r + 1][c] > j) {
							dp[r + 1][c][i + 1][game[r + 1][c]] += dp[r][c][i][j];
							dp[r + 1][c][i + 1][game[r + 1][c]] %= MOD;
						}
					}

					if (c + 1 <= M) {
						if (game[r][c + 1] == 0) {
							dp[r][c + 1][i][j] += dp[r][c][i][j];
							dp[r][c + 1][i][j] %= MOD;
						}
						else if (game[r][c + 1] > j) {
							dp[r][c + 1][i + 1][game[r][c + 1]] += dp[r][c][i][j];
							dp[r][c + 1][i + 1][game[r][c + 1]] %= MOD;
						}
					}
				}
			}
		}
	}


	for (int i = 0; i <= C; i++) {
		int ans = 0;
		for (int j = 0; j <= C; j++) {
			ans = (ans + dp[N][M][i][j]) % MOD;
		}
		cout << ans << ' ';
	}

	return 0;
}