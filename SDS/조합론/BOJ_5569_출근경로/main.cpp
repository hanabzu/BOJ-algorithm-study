/* BOJ_5569 출근 경로 */
/* hanabzu */

#include <iostream>
#define MAXW 100
#define MOD 100000
using namespace std;
enum {
	StoE, StoN, WtoE, WtoN
};
int w, h;
long long dp[4][MAXW + 1][MAXW + 1]; // 0:(S,E), 1:(S,N), 2:(W,E), 3:(W,N)

int main() {
	cin >> w >> h;
	
	for (int i = 1; i <= w; i++) {
		dp[WtoE][1][i] = 1;
	}
	for (int i = 1; i <= h; i++) { 
		dp[StoN][i][1] = 1;
	}

	for (int r = 2; r <= h; r++) {
		for (int c = 2; c <= w; c++) {
			dp[StoN][r][c] = (dp[StoN][r - 1][c] + dp[WtoN][r - 1][c]) % MOD;

			dp[WtoN][r][c] = dp[WtoE][r - 1][c];

			dp[WtoE][r][c] = (dp[WtoE][r][c - 1] + dp[StoE][r][c - 1]) % MOD;

			dp[StoE][r][c] = dp[StoN][r][c - 1];
		}
	}

	cout << (dp[StoE][h][w] + dp[StoN][h][w] + dp[WtoE][h][w] + dp[WtoN][h][w]) % MOD;
	return 0;
}