/* BOJ_1562 계단 수 */
/* hanabzu */

#include <iostream>

using namespace std;

enum {
	NO, BOT, TOP, OK
};
const int MOD = 1000000000;
const int MAXN = 100;

int N, ans = 0;
int dp[MAXN + 1][10][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	if (N < 10) {
		cout << 0;
		return 0;
	}
	else if (N == 10) {
		cout << 1;
		return 0;
	}

	dp[1][9][TOP] = 1;
	for (int i = 1; i < 9; i++) {
		dp[1][i][NO] = 1;
	}

	for (int len = 2; len <= N; len++) {
		dp[len][0][BOT] = (dp[len - 1][1][BOT] + dp[len - 1][1][NO]) % MOD;
		dp[len][0][OK] = (dp[len - 1][1][OK] + dp[len - 1][1][TOP]) % MOD;

		dp[len][9][TOP] = (dp[len - 1][8][TOP] + dp[len - 1][8][NO]) % MOD;
		dp[len][9][OK] = (dp[len - 1][8][OK] + dp[len - 1][8][BOT]) % MOD;


		for (int i = 1; i < 9; i++) {
			for (int j = 0; j < 4; j++) {
				dp[len][i][j] = (dp[len - 1][i - 1][j] + dp[len - 1][i + 1][j]) % MOD;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		ans = (ans + dp[N][i][OK]) % MOD;
	}

	cout << ans;

	return 0;
}
