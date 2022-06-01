/* BOJ_1796 신기한 키보드 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXN = 50;
const int INF = 987654321;
string s;
int N, ans = INF;
int low[27], high[27], dp[27][MAXN];
bool isExist[27];

int dfs(int alpha, int p);
int move(int p, int tar, int wp);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	N = s.size();
	fill(low, low + 27, INF);
	fill(high, high + 27, -1);
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < N; i++) {
		int A = s[i] - 'a';
		isExist[A] = true;
		low[A] = min(low[A], i);
		high[A] = max(high[A], i);
	}
	
	cout << dfs(0, 0) + N;
	return 0;
}


int dfs(int alpha, int p) {
	if (alpha == 26) return 0;
	if (dp[alpha][p] >= 0) return dp[alpha][p];

	int& ret = dp[alpha][p];
	if (isExist[alpha]) {
		ret = min(dfs(alpha + 1, low[alpha]) + move(p, low[alpha], high[alpha]), dfs(alpha + 1, high[alpha]) + move(p, high[alpha], low[alpha]));
	}
	else ret = dfs(alpha + 1, p);
	return ret;
}

int move(int p, int tar, int wp) {
	return abs(p - wp) + abs(wp - tar);
}