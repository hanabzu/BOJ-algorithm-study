/* BOJ_10714 케이크 자르기 2 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2000;

int N;
long long n[MAXN], dp[MAXN][MAXN], ans = 0;

long long dfs(int lhs, int rhs, bool isTurn);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}

	for (int i = 0; i < N; i++) {
		ans = max(ans, n[i] + dfs(i + 1, i - 1, false));
	}
	
	cout << ans;
	return 0;
}


long long dfs(int lhs, int rhs, bool isTurn) {
	if (lhs >= N) lhs -= N;
	if (rhs < 0) rhs += N;
	if (lhs == rhs) {
		if (isTurn) {
			return n[lhs];
		}
		else {
			return 0;
		}
	}

	if (dp[lhs][rhs] > 0) {
		return dp[lhs][rhs];
	}

	if (isTurn) {
		dp[lhs][rhs] = max(n[lhs] + dfs(lhs + 1, rhs, !isTurn),
			n[rhs] + dfs(lhs, rhs - 1, !isTurn));
	}
	else {
		if (n[lhs] < n[rhs]) {
			dp[lhs][rhs] = dfs(lhs, rhs - 1, !isTurn);
		}
		else {
			dp[lhs][rhs] = dfs(lhs + 1, rhs, !isTurn);
		}
	}
	return dp[lhs][rhs];
}