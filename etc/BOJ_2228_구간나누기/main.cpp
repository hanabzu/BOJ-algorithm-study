/* BOJ_2228 구간 나누기 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;
const int INF = 987654321;
int N, M, A[MAXN + 1], dp[MAXN + 1][MAXN >> 1], ans;

int dfs(int p, int m);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&dp[0][0], &dp[MAXN][MAXN >> 1], -INF);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
	}

	cout << dfs(1, M);

	return 0;
}

int dfs(int p, int m) {
	if (m == 0) return 0;
	if (m > 0 && p > N) return -INF - 1;

	if (dp[p][m] != -INF) return dp[p][m];

	int& ret = dp[p][m];
	ret = dfs(p + 1, m);

	for (int rhs = p; rhs <= N; rhs++) {
		ret = max(ret, A[rhs] - A[p - 1] + dfs(rhs + 2, m - 1));
	}
	
	return ret;
}