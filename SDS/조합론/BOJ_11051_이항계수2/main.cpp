/* BOJ_11051 이항계수 2 */
/* hanabzu */

#include <iostream>
#define MAXN 1000
#define MOD 10007
using namespace std;

int N, K, ans;
int dp[MAXN + 1][MAXN + 1];

int pas(int n, int k);

int main() {
	cin >> N >> K;

	cout << pas(N, K);

	return 0;
}

int pas(int n, int k) {
	if (n == 1 || k == 0 || n == k) return 1;
	if (dp[n][k] != 0) return dp[n][k];

	return dp[n][k] = (pas(n - 1, k - 1) + pas(n - 1, k)) % MOD;
}