/* BOJ_24956 나는 정말 휘파람을 못 불어 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;
const int MAXN = 200000;

int N, w = 0, e = 0;
long long ans = 0;
string S;
int num_w[MAXN];
int num_e[MAXN];

long long func(int ne);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'W') w++;
		else if (S[i] == 'H') num_w[i] = w;
	}

	for (int i = S.size() - 1; i >= 0; i--) {
		if (S[i] == 'E') e++;
		else if (S[i] == 'H') num_e[i] = e;
	}

	for (int i = 0; i < S.size(); i++) {
		if (num_w[i] > 0 && num_e[i] > 1) {
			int wn = num_w[i];
			int en = num_e[i];
			ans += (wn * (func(en) - en - 1)) % MOD;
		}
	}
	cout << ans % MOD;
	return 0;
}

long long func(int n) {
	if (n == 1) {
		return 2;
	}
	else if ((n & 1) == 0) {
		long long exp = func(n >> 1);
		return (exp * exp) % MOD;
	}
	else {
		return (func(n - 1) << 1) % MOD;
	}
}
