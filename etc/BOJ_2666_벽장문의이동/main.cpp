/* BOJ_2666 벽장문의 이동 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 20;

int N, M, l, r, A[MAXN];
int dp[MAXN][MAXN + 1][MAXN + 1];

int dfs(int idx, int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&dp[0][0][0], &dp[MAXN - 1][MAXN][MAXN], -1);

	cin >> N >> l >> r >> M;
	for (int i = 0; i < M; i++) cin >> A[i];

	cout << dfs(0, l, r);

	return 0;
}

int dfs(int idx, int lhs, int rhs) {
	if (dp[idx][lhs][rhs] > 0) {
		return dp[idx][lhs][rhs];
	}

	if (idx == M - 1) {
		return dp[idx][lhs][rhs] = min(abs(A[idx] - lhs), abs(A[idx] - rhs));
	}

	dp[idx][lhs][rhs] = min(dfs(idx + 1, A[idx], rhs) + abs(A[idx] - lhs),
							dfs(idx + 1, lhs, A[idx]) + abs(A[idx] - rhs));
	return dp[idx][lhs][rhs];
}