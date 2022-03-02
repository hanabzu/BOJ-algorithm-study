/* BOJ_13977 이항 계수와 쿼리 */
/* hanabzu */

#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 4000000;
const int MOD = 1000000007;

int M, N, K;
ll fact[MAXN + 1], fact_inv[MAXN + 1];
ll mpow(ll a, ll x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fact[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		fact[i] = (i * fact[i - 1]) % MOD;
	}

	fact_inv[MAXN] = mpow(fact[MAXN], MOD - 2);

	for (int i = MAXN - 1; i >= 0; i--) {
		fact_inv[i] = (fact_inv[i + 1] * (i + 1)) % MOD;
	}
	cin >> M;
	while (M--) {
		cin >> N >> K;
		cout << (((fact[N] * fact_inv[K]) % MOD) * fact_inv[N - K]) % MOD<< '\n';
	}

	return 0;
}

ll mpow(ll a, ll x) {
	ll r = 1;
	while (x) {
		if (x % 2 == 1) {
			r = (r * a) % MOD;
		}
		a = (a * a) % MOD;
		x >>= 1;
	}
	return r;
}