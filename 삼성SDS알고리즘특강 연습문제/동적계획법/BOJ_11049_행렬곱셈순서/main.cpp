/* BOJ_11049 행렬 곱셈 순서 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

const int MAXN = 500;

int N, R[MAXN + 1], C[MAXN + 1];
long long dp[MAXN + 1][MAXN + 1];
long long multi(int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> R[i] >> C[i];
	}

	fill(&dp[0][0], &dp[MAXN][MAXN + 1], LLONG_MAX);

	cout << multi(1, N);

	return 0;
}


long long multi(int lhs, int rhs) {
	if (dp[lhs][rhs] != LLONG_MAX) {
		return dp[lhs][rhs];
	}
	if (rhs - lhs == 0) {
		return dp[lhs][rhs] = 0;
	}
	for (int i = lhs; i < rhs; i++) {
		dp[lhs][rhs] = min(dp[lhs][rhs], multi(lhs, i) + multi(i + 1, rhs) + R[lhs] * R[i + 1] * C[rhs]);
	}
	return dp[lhs][rhs];
}