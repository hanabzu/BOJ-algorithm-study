/* BOJ_17779 게리맨더링 2 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 20;

int N, A[MAXN][MAXN], ans = 987654321;

void div(int r, int c, int d1, int d2);

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

	for (int r = 1; r < N - 1; r++) {
		for (int c = 0; c < N - 2; c++) {
			for (int d1 = 1; d1 < (N >>1 ); d1++) {
				for (int d2 = 1; d2 < (N >> 1); d2++) {
					if (r - d1 >= 0 && r + d2 < N && c + d1 + d2 < N) {
						div(r, c, d1, d2);
					}
				}
			}
		}
	}

	cout << ans;

	return 0;
}

void div(int r, int c, int d1, int d2) {
	int p[5] = { 0, };
	bool five[MAXN][MAXN] = { 0, };

	for (int d = 0; d <= d1; d++) {
		five[r - d][c + d] = five[r + d2 - d][c + d2 + d] = true;
	}
	for (int d = 0; d <= d2; d++) {
		five[r + d][c + d] = five[r - d1 + d][c + d1 + d] = true;
	}
	for (int col = c + 1; col < c + d1 + d2; col++) {
		for (int row = 0; ; row++) {
			if (five[row][col]) {
				while (row < N && !five[++row][col]) {
					five[row][col] = true;
				}
				break;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (five[i][j]) {
				p[4] += A[i][j];
			}
			else if (i < r && j <= c + d1) {
				p[0] += A[i][j];
			}
			else if (i <= r - d1 + d2 && j > c + d1) {
				p[1] += A[i][j];
			}
			else if (i >= r && j < c + d2) {
				p[2] += A[i][j];
			}
			else {
				p[3] += A[i][j];
			}
		}
	}

	ans = min(ans, *max_element(p, p + 5) - *min_element(p, p + 5));

}
