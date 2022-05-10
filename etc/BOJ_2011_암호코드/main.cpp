/* BOJ_2011 암호코드 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 50000;
const int MOD = 1000000;
string s;
int dp[MAXN][2], n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	dp[0][0] = (s[0] == '0' ? 0 : 1);
	dp[1][0] = (s[1] == '0' ? 0 : dp[0][0]);
	n = (s[0] - '0') * 10 + s[1] - '0';
	if (n >= 10 && n <= 26) {
		dp[1][1] = 1;
	}


	for (int i = 2; i < s.size(); i++) {
		n = s[i] - '0';

		if (n > 0) {
			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		}

		n += (s[i - 1] - '0') * 10;

		if (n >= 10 && n <= 26) {
			dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % MOD;
		}
	}

	cout << (dp[s.size() - 1][0] + dp[s.size() - 1][1]) % MOD;
	return 0;
}