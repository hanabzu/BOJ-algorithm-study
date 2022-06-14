/* BOJ_2098 외판원 순회 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 16;
const int INF = 987654321;
const int START = 0;
int N, maxb;
int cost[MAXN][MAXN];
int dp[MAXN][1 << MAXN];

int dfs(int n, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}

	maxb = (1 << N) - 1;

	fill(&dp[0][0], &dp[MAXN - 1][1 << MAXN], -1);

	cout << dfs(START, 1 << START);

	return 0;
}

int dfs(int n, int b) {
	if (b == maxb) {
		if (cost[n][START] == 0) {
			return INF;
		}
		else {
			return cost[n][START];
		}
	}

	if (dp[n][b] >= 0 ) {
		return dp[n][b];
	}

	int &ret = dp[n][b] = INF;
	for (int i = 0; i < N; i++) {
		if ((b & (1 << i)) == 0 && cost[n][i] != 0) {
			ret = min(ret, dfs(i, b | (1 << i)) + cost[n][i]);
		}
		
	}
	
	return ret;
}