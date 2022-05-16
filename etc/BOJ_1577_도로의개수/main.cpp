/* BOJ_1577 도로의 개수 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 100;
int N, M, K, a, b, c, d;
bool map[2][MAXN + 1][MAXN + 1];
unsigned long long dp[MAXN + 1][MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	while (K--) {
		cin >> a >> b >> c >> d;
		if (a == c) {
			map[0][a][max(b, d)] = true;
		}
		else {
			map[1][max(a, c)][b] = true;
		}
	}
	for (int i = 0; i <= M; i++) {
		if (map[0][0][i]) break;
		dp[0][i] = 1;
	}

	for (int i = 0; i <= N; i++) {
		if (map[1][i][0]) break;
		dp[i][0] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!map[0][i][j]) dp[i][j] += dp[i][j - 1];
			if (!map[1][i][j]) dp[i][j] += dp[i - 1][j];
		}
	}
	
	cout << dp[N][M];

	return 0;
}