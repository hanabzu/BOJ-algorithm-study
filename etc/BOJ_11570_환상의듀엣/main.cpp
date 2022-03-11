/* BOJ_11570 환상의 듀엣 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2000;

int N, n[MAXN + 1];
int dp[MAXN][MAXN];

int dfs(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&dp[0][0], &dp[MAXN - 1][MAXN], -1);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n[i];
	}

	cout << dfs(0, 0);

	return 0;
}


int dfs(int a, int b) {
	if (a == N || b == N) {
		return 0;
	}
	if (dp[a][b] >= 0) {
		return dp[a][b];
	}
	int next = max(a, b) + 1;
	int a_move = 0, b_move = 0;
	if (a != 0) {
		a_move = abs(n[next] - n[a]);
	}
	if (b != 0) {
		b_move = abs(n[next] - n[b]);
	}
	return dp[a][b] = min(a_move +dfs(next, b), b_move + dfs(a, next));
}