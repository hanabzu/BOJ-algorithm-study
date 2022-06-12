/* BOJ_11048 이동하기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

int N, M, A[MAXN + 1][MAXN + 1], dp[MAXN + 1][MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = A[i][j] + max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
		}
	}

	cout << dp[N][M];
	return 0;
}