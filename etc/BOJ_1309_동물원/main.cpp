/* BOJ_1309 동물원 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 100000;
const int MOD = 9901;

int N, dp[3][MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	dp[0][0] = dp[1][0] = dp[2][0] = 1;

	for (int i = 1; i < N; i++) {
		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % MOD;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
	}

	cout << (dp[0][N - 1] + dp[1][N - 1] + dp[2][N - 1]) % MOD;
	return 0;
}