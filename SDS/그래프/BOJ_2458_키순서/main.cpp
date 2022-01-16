/* BOJ_2458 키 순서 */
/* hanabzu */

#include <iostream>
#include <limits.h>
#define MAXN 500
using namespace std;

int N, M, a, b, answer;
bool dp[MAXN + 1][MAXN + 1];
bool check[MAXN + 1][MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		cin >> a >> b; // a.len < b.len
		dp[a][b] = true;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) {
					continue;
				}
				if (!dp[i][k] || !dp[k][j]) {
					continue;
				}
				dp[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dp[i][j] = true;
			if (dp[i][j]) {
				dp[j][i] = true;
			}
		}
	}

	answer = N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!dp[i][j]) {
				answer--;
				break;
			}
		}
	}

	cout << answer;

	return 0;
}