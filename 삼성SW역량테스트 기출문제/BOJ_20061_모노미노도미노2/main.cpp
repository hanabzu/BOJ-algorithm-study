/* hanabzu */
/* BOJ_20061 모노미노도미노 2 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, t, x, y, score, num;
vector<vector<bool>> green, blue;

void placeBlock(vector<vector<bool>>& table, int x, int block);
void checkLine(vector<vector<bool>>& table);
void countBlock();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 6; i++) {
		green.push_back(vector<bool>(4));
		blue.push_back(vector<bool>(4));
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t >> x >> y;
		placeBlock(green, y, t);
		if (t > 1) {
			t = 5 - t;
		}
		placeBlock(blue, x, t);
	}

	countBlock();
	cout << score << '\n' << num;
	return 0;
}


void placeBlock(vector<vector<bool>>& table, int col, int block) {
	switch (block) {
	case 1:
		for (int row = 3;; row--) {
			if (row < 0) {
				table[0][col] = 1;
				break;
			}
			else if (table[row][col]) {
				table[row + 1][col] = 1;
				break;
			}
		}
		break;
	case 2:
		for (int row = 3;; row--) {
			if (row < 0) {
				table[0][col] = table[0][col + 1] = 1;
				break;
			}
			else if (table[row][col] | table[row][col + 1]) {
				table[row + 1][col] = table[row + 1][col + 1] = 1;
				break;
			}

		}
		break;
	case 3:
		for (int row = 3;; row--) {
			if (row < 0) {
				table[0][col] = table[1][col] = 1;
				break;
			}
			else if (table[row][col]) {
				table[row + 1][col] = table[row + 2][col] = 1;
				break;
			}
		}
	}

	checkLine(table);
}


void checkLine(vector<vector<bool>>& table) {
	for (int col = 0; col < 4; col++) {
		while (table[col][0] & table[col][1] & table[col][2] & table[col][3]) {
			table.erase(table.begin() + col);
			table.push_back(vector<bool>(4));
			score++;
		}
	}
	while (table[4][0] | table[4][1] | table[4][2] | table[4][3]) {
		table.erase(table.begin());
		table.push_back(vector<bool>(4));
	}
}

void countBlock() {
	vector<vector<bool>>* p[2] = { &green, &blue };
	for (int i = 0; i < 2; i++) {
		for (vector<vector<bool>>::iterator line = (*p[i]).begin(); line != (*p[i]).end(); line++) {
			num += count((*line).begin(), (*line).end(), 1);
		}
	}
}
