/* BOJ_2449 전구 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200;
const int MAXK = 20;
const int INF = 987654321;
int N, K;
int n[MAXN];
int dp[MAXK+1][MAXN][MAXN];

int dfs(int k, int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}

	cout << dfs(n[0], 0, N - 1);

	return 0;
}

int dfs(int k, int lhs, int rhs) {
	if (lhs == rhs) {
		return 0;
	}
	if (dp[k][lhs][rhs] > 0) {
		return dp[k][lhs][rhs];
	}

	dp[k][lhs][rhs] = INF;
	for (int i = lhs + 1; i <= rhs; i++) {
		dp[k][lhs][rhs] = min(dp[k][lhs][rhs], dfs(k, lhs, i - 1) + dfs(n[i], i, rhs) + (k != n[i]));
	}
	return dp[k][lhs][rhs];
}