/* BOJ_1937 욕심쟁이 판다 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 500;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

int N, A[MAXN][MAXN], dp[MAXN][MAXN], ans;

int dfs(int r, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, dfs(i, j));
		}
	}
	cout << ans;
	return 0;
}

int dfs(int r, int c) {
	int& ret = dp[r][c];
	if (ret > 0) return ret;

	ret = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N || A[nr][nc] <= A[r][c]) continue;

		ret = max(ret, 1 + dfs(nr, nc));
	}

	return ret;
}