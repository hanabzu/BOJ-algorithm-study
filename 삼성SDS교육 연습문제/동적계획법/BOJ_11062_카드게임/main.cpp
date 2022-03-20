/* BOJ_11062 카드 게임 */
/* hanabzu */

#include <iostream>
#include <string.h>
using namespace std;

const int MAXN = 1000;

int T, N, n[MAXN], dp[MAXN][MAXN];

void sol();
int dfs(int lhs, int rhs, bool isTurn);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		sol();
	}

	return 0;
}

void sol() {
	memset(dp, 0, sizeof(dp));

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}

	cout << dfs(0, N - 1, true) << '\n';
}

int dfs(int lhs, int rhs, bool isTurn) {
	if (lhs > rhs) {
		return 0;
	}
	if (dp[lhs][rhs]) {
		return dp[lhs][rhs];
	}
	if (!isTurn) {
		return dp[lhs][rhs] = min(dfs(lhs + 1, rhs, !isTurn), dfs(lhs, rhs - 1, !isTurn));
	}
	return dp[lhs][rhs] = max(n[lhs] + dfs(lhs + 1, rhs, !isTurn), n[rhs] + dfs(lhs, rhs - 1, !isTurn));
}