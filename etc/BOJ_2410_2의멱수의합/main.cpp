/* BOJ_2410 2의 멱수의 합 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 1000000;
const int MOD = 1000000000;
int N, dp[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;
	dp[0] = 1;
	for (int i = 1; i <= N; i<<=1) {
		for (int j = i; j <=N; j++) {
			dp[j] = (dp[j] + dp[j - i]) % MOD;
		}
	}
	cout << dp[N];
	return 0;
}