/* hanabzu */
/* BOJ_14500 테트로미노 */

#include <iostream>

using namespace std;

int N, M, sum, maximum = 0;
int matrix[503][503] = { 0, };

int tetromino[19][4][2] = { {{0,0},{0,1},{0,2},{0,3}}, // horizon line
						    {{0,0},{1,0},{2,0},{3,0}}, // vertical line
						    {{0,0},{1,0},{0,1},{1,1}}, // square
						    {{0,0},{1,0},{2,0},{2,1}}, // L
					   	    {{0,0},{1,0},{0,1},{0,2}},
						    {{0,0},{0,1},{1,1},{2,1}},
						    {{1,0},{1,1},{1,2},{0,2}},
						    {{0,0},{0,1},{0,2},{1,2}}, // reversed L
						    {{0,1},{1,1},{2,1},{2,0}},
						    {{0,0},{1,0},{1,1},{1,2}},
						    {{0,0},{1,0},{2,0},{0,1}},
						    {{1,0},{0,1},{1,1},{2,0}}, // N
						    {{0,0},{0,1},{1,1},{1,2}},
						    {{0,0},{1,0},{1,1},{2,1}}, // reversed N
						    {{1,0},{1,1},{0,1},{0,2}},
						    {{0,0},{0,1},{0,2},{1,1}}, // T
						    {{1,0},{0,1},{1,1},{2,1}},
						    {{1,0},{0,1},{1,1},{1,2}},
						    {{0,0},{1,0},{2,0},{1,1}} };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 19; k++) {
				sum = matrix[i + tetromino[k][0][0]][j + tetromino[k][0][1]]
					+ matrix[i + tetromino[k][1][0]][j + tetromino[k][1][1]]
					+ matrix[i + tetromino[k][2][0]][j + tetromino[k][2][1]]
					+ matrix[i + tetromino[k][3][0]][j + tetromino[k][3][1]];
				if (sum > maximum) {
					maximum = sum;
				}
			}
		}
	}

	cout << maximum;

	return 0;
}