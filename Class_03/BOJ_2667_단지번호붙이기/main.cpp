/* hanabzu */
/* BOJ_2667 numbering clusters */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findBlock(int i, int j);

int** matrix;
vector<int> volumes;
int N;
string M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	// dynamic allocation
	matrix = new int*[N + 2];
	for (int i = 0; i < N + 2; i++) {
		matrix[i] = new int[N + 2];

		// padding
		matrix[i][0] = matrix[i][N + 1] = 0;
		if (i == 0 || i == N + 1) {
			for (int j = 1; j < N + 2; j++) {
				matrix[i][j] = 2;
			}
		}
	}

	// read data
	for (int i = 1; i <= N; i++) {
		cin >> M;
		for (int j = 1; j <= N; j++) {
			matrix[i][j] = M[j - 1]- '0';
		}
	}

	// find blocks
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (matrix[i][j] == 1) {
				volumes.push_back(findBlock(i, j));
			}
		}
	}
	sort(volumes.begin(), volumes.end());

	cout << volumes.size() << '\n';

	for (vector<int>::iterator iter = volumes.begin(); iter != volumes.end(); iter++) {
		cout << *iter << '\n';
	}

	for (int i = 0; i < N + 2; i++) {
		delete[] matrix[i];
	}
}

int findBlock(int i, int j) {
	// init
	int num = 1;
	matrix[i][j] = 2;
	
	// find connected aparts

	// north
	if (matrix[i - 1][j] == 1) {
		num += findBlock(i - 1, j);
	}
	else {
		matrix[i - 1][j] = 2;
	}

	// south
	if (matrix[i + 1][j] == 1) {
		num += findBlock(i + 1, j);
	}
	else {
		matrix[i + 1][j] == 2;
	}

	//west
	if (matrix[i][j - 1] == 1) {
		num += findBlock(i, j - 1);
	}
	else {
		matrix[i][j - 1] == 2;
	}

	//east
	if (matrix[i][j + 1] == 1) {
		num += findBlock(i, j + 1);
	}
	else {
		matrix[i][j + 1] == 2;
	}

	return num;
}