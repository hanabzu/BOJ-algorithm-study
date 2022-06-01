/* BOJ_2216 문자열과 점수 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 3001;
const int INF = 987654321;

int A, B, C;
string X, Y;
int dp[MAXN][MAXN];

int dfs(int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C >> X >> Y;

	fill(&dp[0][0], &dp[MAXN - 1][MAXN], -INF);

	cout << dfs(0, 0);

	return 0;
}

int dfs(int lhs, int rhs) {
	if (lhs == X.size() && rhs == Y.size()) return 0;
	if (dp[lhs][rhs] != -INF) return dp[lhs][rhs];

	int& ret = dp[lhs][rhs];
	if (lhs < X.size() && rhs < Y.size()) {
		ret = ((X[lhs] == Y[rhs]) ? A : C) + dfs(lhs + 1, rhs + 1);
	}
	if (lhs < X.size()) {
		ret = max(ret, B + dfs(lhs + 1, rhs));
	}
	if (rhs < Y.size()) {
		ret = max(ret, B + dfs(lhs, rhs + 1));
	}

	return ret;
}
