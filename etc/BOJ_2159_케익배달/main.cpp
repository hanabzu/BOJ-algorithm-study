/* BOJ_2159 케익 배달 */
/* hanabzu */

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
const int dx[5] = { 0,-1,0,1,0 };
const int dy[5] = { 0,0,-1,0,1 };
const long long INF = 111987654321;

long long N, X[MAXN+1], Y[MAXN + 1], dp[MAXN + 1][5], ans = INF;

long long dfs(int p, int i);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i <= N; i++) {
		cin >> X[i] >> Y[i];
	}

	memset(dp, -1, sizeof dp);

	for (int i = 0; i < 5; i++) {
		ans = min(ans, dfs(N, i));
	}

	cout << ans;

	return 0;
}


long long dfs(int p, int i) {
	if (dp[p][i] >= 0) return dp[p][i];

	long long& ret = dp[p][i];

	int x = X[p] + dx[i];
	int y = Y[p] + dy[i];
	
	if (p == 1) {
		return ret = abs(X[0] - x) + abs(Y[0] - y);
	}

	ret = INF;
	for (int d = 0; d < 5; d++) {
		ret = min(ret, dfs(p - 1, d) + abs(X[p - 1] + dx[d] - x) + abs(Y[p - 1] + dy[d] - y));
	}
	

	return ret;
}