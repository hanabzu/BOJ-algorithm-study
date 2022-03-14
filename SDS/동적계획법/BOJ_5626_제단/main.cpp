/* BOJ_5626 제단 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXN = 10000;
const long long MOD = 1000000007;

int N, n[MAXN];
long long dp[2][(MAXN >> 1) + 5]; // max height is half of N

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
		if (n[i] != -1) n[i]++;
	}

	dp[0][1] = n[0] <= 1 ? 1 : 0;

	int idx = 1;
	for (int i = 1; i < N; i++, idx = 1 - idx) {
		memset(dp[idx], 0, sizeof(dp[idx])); // reset buffer
		int pre = 1 - idx;
		if (n[i] == -1) {
			for (int h = 1; h <= (N >> 1) + 1; h++) {
				dp[idx][h] = (dp[pre][h - 1] + dp[pre][h] + dp[pre][h + 1]) % MOD;
			}
		}
		else {
			dp[idx][n[i]] = (dp[pre][n[i] - 1] + dp[pre][n[i]] + dp[pre][n[i] + 1]) % MOD;
		}
	}

	cout << dp[1 - idx][1];

	return 0;
}