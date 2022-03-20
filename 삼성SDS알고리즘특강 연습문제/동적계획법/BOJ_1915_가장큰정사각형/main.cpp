/* BOJ_1915 가장 큰 정사각형 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#define MAXN 1000
using namespace std;

int n, m, res = 0;
int dp[MAXN + 1][MAXN + 1];
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			if (s[j-1]=='1') {
				dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1],dp[i - 1][j - 1] }) + 1;
			}
			res = max(dp[i][j], res);
		}
	}
	cout << res * res;

	return 0;
}