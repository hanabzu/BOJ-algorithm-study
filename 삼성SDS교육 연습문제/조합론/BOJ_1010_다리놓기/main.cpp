/* BOJ_1010 다리 놓기 */
/* hanabzu */

#include <iostream>
#define MAXN 30
using namespace std;

int t, N, M;
int dp[MAXN + 1][MAXN + 1];
int pas(int n, int k);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> N >> M;
		cout << pas(M, N) << '\n';
	}

	return 0;
}

int pas(int n, int k) {
	if (n == 1 || k == 0 || n == k) return 1;
	if (dp[n][k] != 0) return dp[n][k];

	return dp[n][k] = pas(n - 1, k - 1) + pas(n - 1, k);
}