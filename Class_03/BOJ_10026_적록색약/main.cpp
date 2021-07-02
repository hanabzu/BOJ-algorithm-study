/* hanabzu */
/* BOJ_10026 적록색약 */

#include <iostream>

using namespace std;

int human[102][102] = { 0, };
int cow[102][102] = { 0, };
int dir[2][4] = { {-1,1,0,0},{0,0,-1,1} };
int N;
string line;

void BFS(int [102][102]);
void find(int [102][102], int row, int col, int value);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> line;
		for (int j = 0; j < N; j++) {
			switch (line[j]) {
			case 'B':
				human[i][j + 1] = cow[i][j + 1] = 1;
				break;
			case 'R':
				human[i][j + 1] = cow[i][j + 1] = 2;
				break;
			case 'G':
				human[i][j + 1] = 3;
				cow[i][j + 1] = 2;
			}
		}
	}

	BFS(human);
	BFS(cow);


	return 0;
}

void BFS(int mat[102][102]) {
	int section = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (mat[i][j] != 0) {
				find(mat, i, j, mat[i][j]);
				section++;
			}
		}
	}
	cout << section << ' ';
}

void find(int mat[102][102], int row, int col, int value) {
	mat[row][col] = 0;

	for (int i = 0; i < 4; i++) {
		if (mat[row + dir[0][i]][col + dir[1][i]] == value) {
			find(mat, row + dir[0][i], col + dir[1][i], value);
		}
	}
}