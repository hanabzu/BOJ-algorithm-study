/* BOJ_2281 데스노트 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXN = 1000;

int N, M;
int A[MAXN], dp[MAXN][MAXN];

int get_min(int n, int remain);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof dp);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << get_min(0, M - A[0]);

	return 0;
}

int get_min(int n, int remain) {
	if (n == N - 1) return 0;
	if (dp[n][remain] >= 0) return dp[n][remain];

	int& res = dp[n][remain];

	res = remain * remain + get_min(n + 1, M - A[n + 1]);
	if (A[n + 1] < remain) {
		res = min(res, get_min(n + 1, remain - A[n + 1] - 1));
	}

	return res;
}