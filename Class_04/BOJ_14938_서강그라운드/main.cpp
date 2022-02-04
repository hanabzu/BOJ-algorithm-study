/* BOJ_14938 서강그라운드 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;
const int INF = 987654321;

int dp[MAXN + 1][MAXN + 1];
int t[MAXN + 1], maxt[MAXN + 1];
int n, m, r, a, b, l;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(&dp[0][0], &dp[MAXN][MAXN+1], INF);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}


	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		dp[a][b] = dp[b][a] = l;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				if (dp[i][k] == INF || dp[k][j] == INF) {
					continue;
				}
				if (dp[i][k] + dp[k][j] < dp[i][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				maxt[i] += t[i];
			}
			else if (dp[i][j] <= m) {
				maxt[i] += t[j];
			}
		}
	}

	cout << *max_element(maxt, maxt + n + 1);

	return 0;
}