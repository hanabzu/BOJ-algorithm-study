/* hanabzu */
/* BOJ_1780 종이의 개수 */

#include <iostream>

using namespace std;

int N, paper_num[3] = { 0, 0, 0 };
int mat[2187][2187];

void cut(int row, int col, int size);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}

	cut(0, 0, N);

	cout << paper_num[0] << '\n' << paper_num[1]  << '\n' << paper_num[2];

	return 0;
}

void cut(int row, int col, int size) {
	int paper = mat[row][col];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (mat[row + i][col + j] != paper) {
				cut(row, col, size/3);
				cut(row + (size / 3), col, size / 3);
				cut(row + ((size / 3) << 1), col, size / 3);
				cut(row, col + (size / 3), size / 3);
				cut(row, col + ((size / 3) << 1), size / 3);
				cut(row + (size / 3) , col + (size / 3), size / 3);
				cut(row + (size / 3), col + ((size / 3) << 1), size / 3);
				cut(row + ((size / 3) << 1), col + (size / 3), size / 3);
				cut(row + ((size / 3) << 1), col + ((size / 3) << 1), size / 3);
				return;
			}
		}
	}
	paper_num[paper+1]++;
}