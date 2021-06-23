/* hanabzu */
/* BOJ_1012 유기농 배추 */

#include <iostream>
#include <string.h>

using namespace std;

int mat[52][52] = { 0, }; // padding
int T, M, N, K, X, Y;
int dir[2][4] = { {-1,1,0,0},{0,0,-1,1} };

void find(int row, int col);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		int result = 0;
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			mat[X + 1][Y + 1] = 1;
		}

		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (mat[i][j] == 1) {
					find(i, j);
					result++;
				}
			}
		}

		cout << result << '\n';

		for (int i = 1; i < M + 1; i++) { // reset matrix
			memset(mat[i], 0, sizeof(int) * N);
		}
	}

	return 0;

}

void find(int row, int col) {
	mat[row][col] = 2;

	for (int i = 0; i < 4; i++) {
		if (mat[row + dir[0][i]][col + dir[1][i]] == 1) {
			find(row + dir[0][i], col + dir[1][i]);
		}
		else {
			mat[row + dir[0][i]][col + dir[1][i]] = 2;
		}
	}
}