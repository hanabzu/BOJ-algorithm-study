/* BOJ_1086 박성원 */
/* hanabzu */

#include <iostream>
#include <numeric>
#include <string.h>

using namespace std;
const int MAXN = 15;
const int MAXK = 100;
const int MAXLEN = 50;

int N, K;
string s[MAXN];
int pten[MAXLEN + 1], ten[MAXN], num[MAXN], MAXB;
long long p = 0, q = 1;
long long dp[1 << MAXN][MAXK];

long long dfs(int r, int b);
int div(string str);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;
	for (int i = 2; i <= N; i++) { // q = fact(N)
		q *= i;
	}
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	cin >> K;
	for (int i = 0; i < N; i++) {
		ten[i] = s[i].size();
		num[i] = div(s[i]);
	}

	pten[0] = 1 % K;
	for (int i = 1; i <= MAXLEN; i++) {
		pten[i] = (pten[i - 1] * 10) % K;
	}

	MAXB = (1 << N) - 1;

	memset(dp, -1, sizeof(dp));
	p = dfs(0, 0);
	long long g = gcd(p, q);
	p /= g;
	q /= g;
	cout << p << '/' << q;
	return 0;
}

long long dfs(int r, int b) {
	if (dp[b][r] != -1) {
		return dp[b][r];
	}

	if (b == MAXB) {
		if (r) return dp[b][r] = 0;
		else return dp[b][r] = 1;
	}

	dp[b][r] = 0;
	for (int i = 0; i < N; i++) {
		if (!(b & (1 << i))) {
			dp[b][r] += dfs((r * pten[ten[i]] + num[i]) % K, b | (1 << i));
		}
	}
	return dp[b][r];
}

int div(string str) {
	int r = 0;
	for (int i = 0; i < str.size(); i++) {
		r = (r * 10 + (str[i] - '0')) % K;
	}
	return r;
}