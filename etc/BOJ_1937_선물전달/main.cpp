/* BOJ_1947 선물 전달 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 1000000;
const int MOD = 1000000000;

int N;
long long dp[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i <= N; i++) {
		dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
	}
	cout << dp[N];
	return 0;
}