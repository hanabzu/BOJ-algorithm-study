/* BOJ_2229 조 짜기 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1000;
const int INF = 987654321;

int N, A[MAXN], dp[MAXN][MAXN];
int  diff[MAXN][MAXN];
int div_team(int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&dp[0][0], &dp[MAXN - 1][MAXN], -1);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		int mn = INF, mx = 0;
		for (int j = i; j < N; j++) {
			mn = min(mn, A[j]);
			mx = max(mx, A[j]);

			diff[i][j] = mx - mn;
		}
	}

	cout << div_team(0, N - 1);

	return 0;
}

int div_team(int lhs, int rhs) {
	if (dp[lhs][rhs] >= 0) {
		return dp[lhs][rhs];
	}

	int ans = diff[lhs][rhs];
	for (int i = lhs; i < rhs; i++) {
		ans = max(ans, diff[lhs][i] + div_team(i + 1, rhs));
	}

	return dp[lhs][rhs] = ans;
}