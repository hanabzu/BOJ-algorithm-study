/* BOJ_1890 점프 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 100;

int N;
int A[MAXN][MAXN];
long long dp[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	dp[0][0] = 1;
	int ni, nj;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 0) continue;
			ni = i + A[i][j];
			nj = j + A[i][j];

			if (ni < N) {
				dp[ni][j] += dp[i][j];
			}
			if (nj < N) {
				dp[i][nj] += dp[i][j];
			}
		}
	}
	
	cout << dp[N - 1][N - 1];
	return 0;
}