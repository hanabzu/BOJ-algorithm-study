/* BOJ_1670 정상 회담 2 */
/* hanabzu */

#include <iostream>
#include <string.h>
using namespace std;

const int MAXN = 10000;
const int MOD = 987654321;

int N;
long long dp[MAXN + 1];

long long get_combi(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	dp[0] = dp[2] = 1;
	cout << get_combi(N);

	return 0;
}


long long get_combi(int n) {
	if (dp[n] > 0) return dp[n];
	for (int i = 2; i <= n; i += 2) {
		dp[n] = (dp[n] + get_combi(i - 2) * get_combi(n - i)) % MOD;
	}
	return dp[n];
}