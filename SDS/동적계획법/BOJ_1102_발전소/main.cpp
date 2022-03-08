/* BOJ_1102 발전소 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 16;
const int INF = 987654321;
int N, P, B, num;
int dp[1 << MAXN];
int cost[MAXN][MAXN];
string s;

int dfs(int b, int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
	cin >> s >> P;
	for (int i = 0; i < s.size(); i++) {
		B <<= 1;
		if (s[N - i - 1] == 'Y') {
			B |= 1;
			num++;
		}
	}

	fill(dp, dp + (1 << MAXN), -1);
	cout << dfs(B, num);

	return 0;
}

int dfs(int b, int n) {
	if (n >= P) {
		return 0;
	}
	if (n == 0) {
		return -1;
	}
	if (dp[b] >= 0) {
		return dp[b];
	}

	dp[b] = INF;
	for (int i = 0; i < N; i++) {
		if (b & (1 << i)) {
			for (int j = 0; j < N; j++) {
				if (!(b & (1 << j))) {
					dp[b] = min(dp[b], cost[i][j] + dfs(b | (1 << j), n + 1));
				}
			}
		}
	}

	return dp[b];
}