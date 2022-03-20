/* hanabzu */
/* BOJ_5582 공통 부분 문자열 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 4000;
string X, Y;
int X_len, Y_len, ans = 0;
int dp[MAXN+1][MAXN+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> X >> Y;
	X_len = X.length();
	Y_len = Y.length();
	for (int i = 0; i < X_len; i++) {
		for (int j = 0; j < Y_len; j++) {
			if (X[i] == Y[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				ans = max(ans, dp[i + 1][j + 1]);
			}
		}
	}

	cout << ans;
	return 0;
}