/* BOJ_5573 산책 */
/* hanabzu */

#include <iostream>
#define MAXH 1000
using namespace std;

int H, W, N;
bool m[MAXH + 1][MAXH + 1];
int dp[2][MAXH + 1][MAXH + 1];
int sdp[2][MAXH + 1][MAXH + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> H >> W >> N;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> m[i][j];
		}
	}

	dp[0][0][1] = N;
	sdp[0][0][1] = N - 1;

	// 0 -> down, 1 -> right
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			int c = dp[0][i - 1][j] + dp[1][i][j - 1];
			int sc = sdp[0][i - 1][j] + sdp[1][i][j - 1];
			dp[m[i][j]][i][j] = dp[!m[i][j]][i][j] = c >> 1;
			sdp[m[i][j]][i][j] = sdp[!m[i][j]][i][j] = sc >> 1;
			if (c & 1) { // odd
				dp[m[i][j]][i][j]++;
			}
			if (sc & 1) { // odd
				sdp[m[i][j]][i][j]++;
			}
		}
	}

	for (int i = 1; i <= H; i++) {
		if (dp[1][i][W] - sdp[1][i][W]) {
			cout << i << ' ' << W + 1;
			return 0;
		}
	}

	for (int i = 1; i <= W; i++) {
		if (dp[0][H][i] - sdp[0][H][i]) {
			cout << H + 1 << ' ' << i;
			return 0;
		}
	}

	return 0;
}
