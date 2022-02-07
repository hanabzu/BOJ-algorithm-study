/* BOJ_2342 Dance Dance Revolution */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int dp[MAXN + 1][5][5], input[MAXN + 1];
int N = 0;

int dfs(int p, int lhs, int rhs);
int move(int s, int e);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> input[N];
		if (input[N] == 0) break;
		N++;
	}

	cout << dfs(0, 0, 0);
	return 0;
}

int dfs(int p, int lhs, int rhs) {
	if (input[p] == 0) {
		return 0;
	}

	if (dp[p][lhs][rhs] > 0) return dp[p][lhs][rhs];

	int next_lhs = dfs(p + 1, input[p], rhs) + move(lhs, input[p]);
	int next_rhs = dfs(p + 1, lhs, input[p]) + move(rhs, input[p]);

	return dp[p][lhs][rhs] = min(next_lhs, next_rhs);
}

int move(int s, int e) {
	if (s == e) {
		return 1;
	}
	else if (s == 0) {
		return 2;
	}
	else if (((s + e) & 1) == 1) {
		return 3;
	}
	else {
		return 4;
	}
}