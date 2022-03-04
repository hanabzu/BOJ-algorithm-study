/* BOJ_16565 N포커 */
/* hanabzu */

#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 10007;
const int MAXN = 52;

ll dp[MAXN][MAXN + 1] = { 0, };
ll ans = 0;
int N, Q;

ll combi(ll n, ll r);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	Q = N >> 2;

	for (int i = 1; i <= Q; i++) {
		ll sign = (i & 1) ? 1 : -1;
		ans += (sign * combi(13, i) * combi(MAXN - (i << 2), N - (i << 2))) % MOD;
		ans = (ans % MOD + MOD) % MOD;
	}

	cout << ans;

	return 0;
}

ll combi(ll n, ll r) {
	if (dp[n][r]) {
		return dp[n][r];
	}
	if (n == r || r == 0) {
		return dp[n][r] = 1;
	}

	return dp[n][r] = (combi(n - 1, r - 1) + combi(n - 1, r)) % MOD;
}
