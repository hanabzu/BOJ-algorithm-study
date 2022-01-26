/* BOJ_1256 사전 */
/* hanabzu */

#include <iostream>
#define MAXN 200
#define MAXK 1000000000
using namespace std;

int N, M, K;
int dp[MAXN + 1][MAXN + 1];
int pas(int n, int k);

int main() {
	cin >> N >> M >> K;

	dp[0][0] = 1;

	N += M;

	if (pas(N, M) < K) {
		cout << -1;
		return 0;
	}

	for (int i = N; i > 0; i--) {
		if (dp[i - 1][M] >= K) {
			cout << 'a';
		}
		else {
			cout << 'z';
			K -= dp[i - 1][M--];
		}
	}

	return 0;
}
int pas(int n, int k) {
	if (dp[n][k] != 0) return dp[n][k];
	if (n == 1 || k == 0 || n == k) return dp[n][k] = 1;
	dp[n][k] = pas(n - 1, k - 1) + pas(n - 1, k);
	if (dp[n][k] > MAXK) {
		return dp[n][k] = MAXK +1;
	}
	return dp[n][k];
}