/* BOJ_17070 파이프 옮기기 1 */
/* hanabzu */

#include <iostream>

using namespace std;

int N;
int mat[17][17];
int route[3][16][16]; //[0] = horizon, [1] = diagonal, [2] = vertical

void get_route(int row, int col);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		mat[N][i] = mat[i][N] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}

	// start route
	route[0][0][1] = 1;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i - j >= 0) {
				get_route(i-j, j);
			}
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i + j < N) {
				get_route(i + j, N-j-1);
			}
		}
	}

	cout << route[0][N - 1][N - 1] + route[1][N - 1][N - 1] + route[2][N - 1][N - 1];
	return 0;
}

void get_route(int row, int col) {
	bool right = mat[row][col + 1];
	bool down = mat[row + 1][col];
	bool diagonal = right | down | mat[row + 1][col + 1];

	if (!right) {
		route[0][row][col + 1] += (route[0][row][col]+ route[1][row][col]);
	}
	if (!down) {
		route[2][row + 1][col] += (route[2][row][col] + route[1][row][col]);
	}
	if (!diagonal) {
		route[1][row + 1][col+1] += (route[0][row][col] + route[1][row][col] + route[2][row][col]);
	}
}