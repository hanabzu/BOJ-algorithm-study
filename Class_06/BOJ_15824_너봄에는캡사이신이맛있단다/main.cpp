/* BOJ_15824 너 봄에는 캡사이신이 맛있단다 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAXN = 300000;
const ll MOD = 1000000007;

int N;
ll n[MAXN], ans = 0;

ll mpow(ll a, ll x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}

	sort(n, n + N);

	for (int i = 0; i < N; i++) {
		ans += (mpow(2, i) * (n[i] % MOD)) % MOD; // n[i] is max
		ans -= (mpow(2, N - i - 1) * (n[i] % MOD)) % MOD; // n[i] is min
		ans = (ans % MOD + MOD) % MOD; // concerns minus MOD
	}

	cout << ans;
	return 0;

}

ll mpow(ll a, ll x) {
	ll r = 1;
	while (x) {
		if ((x & 1) == 1) {
			r = (r * a) % MOD;
		}
		x >>= 1;
		a = (a * a) % MOD;
	}

	return r;
}