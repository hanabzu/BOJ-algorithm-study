/* BOJ_11057 오르막 수 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 1000;
const int MOD = 10007;

int N, dp[MAXN][10], ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < 10; i++) {
		dp[0][i] = 1;
	}

	for (int n = 1; n < N; n++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j <= i; j++) {
				dp[n][i] = (dp[n][i] + dp[n-1][j])%MOD;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		ans = (ans + dp[N - 1][i]) % MOD;
	}
	cout << ans;

	return 0;
}