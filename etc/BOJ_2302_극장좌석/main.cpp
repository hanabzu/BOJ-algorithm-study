/* BOJ_2302 극장 좌석 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 40;

int N, M, a;
bool locked[MAXN];

int dp[2][MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	while (M--) {
		cin >> a;
		locked[a - 1] = true;
	}

	dp[0][0] = 1;
	
	for (int i = 1; i < N; i++) {
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		
		if (!locked[i] && !locked[i - 1]) {
			dp[1][i] = dp[0][i - 1];
		}
	}
	
	cout << dp[0][N - 1] + dp[1][N - 1];
	return 0;
}