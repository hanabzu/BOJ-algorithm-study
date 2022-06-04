/* BOJ_2253 점프 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXS = 200;
const int MAXN = 10000;
const int ds[3] = { -1,0,1 };
const int INF = 987654321;

int N, M, x, dp[MAXS][MAXN + 1], ans = INF;
bool X[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	while (M--) {
		cin >> x;
		X[x] = true;
	}
	
	fill(&dp[0][0], &dp[MAXS - 1][MAXN + 1], INF);
	
	if(!X[2]) dp[1][2] = 1; // cannot jump to the second stone

	for (int i = 2; i <= N; i++) { // num
		for (int s = 1; s < MAXS; s++) { // speed
			if (dp[s][i] == INF) continue;

			for (int d = 0; d < 3; d++) {
				int ns = s + ds[d];
				if (ns <= 0 || i + ns > N || X[i + ns] == true) continue;

				dp[ns][i + ns] = min(dp[s][i] + 1, dp[ns][i + ns]);
			}
		}
	}
	for (int i = 1; i < MAXS; i++) {
		ans = min(ans, dp[i][N]);
	}
	cout << ((ans == INF) ? -1 : ans);
	return 0;
}