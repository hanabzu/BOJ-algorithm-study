/* BOJ_11404 플로이드 */
/* hanabzu */

#include <iostream>
#include <limits.h>
#define MAXN 100
using namespace std;

int n, m, a, b, c;
int dp[MAXN + 1][MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = INT_MAX;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (dp[a][b] > c) {
			dp[a][b] = c;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				if (dp[i][k] == INT_MAX || dp[k][j] == INT_MAX) {
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
			if(dp[i][j]== INT_MAX)
				cout << 0 << ' ';
			else
				cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;

}