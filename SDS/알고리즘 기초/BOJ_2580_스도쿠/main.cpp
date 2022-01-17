/* BOJ_2580 스도쿠 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int sudoku[9][9];
int n_blank = 0;
vector<pii> blank;

void back_track(vector<pii>::iterator p, int depth);
bool check(vector<pii>::iterator p, int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (!sudoku[i][j]) {
				blank.push_back(make_pair(i, j));
				n_blank++;
			}
		}
	}

	back_track(blank.begin(), 0);
	return 0;
}

void back_track(vector<pii>::iterator p, int depth) {
	if (depth == n_blank) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	for (int i = 1; i <= 9; i++) {
		if (check(p, i)) {
			sudoku[(*p).first][(*p).second] = i;
			back_track(p + 1, depth + 1);
			sudoku[(*p).first][(*p).second] = 0;
		}
	}

}

bool check(vector<pii>::iterator p, int n) {
	int r = (*p).first, c =(*p).second;

	for (int i = 0; i < 9; i++) {
		if (sudoku[r][i] == n || sudoku[i][c] == n) {
			return false;
		}
	}
	r /= 3;
	c /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (sudoku[3 * r + i][3 * c + j] == n) {
				return false;
			}
		}

	}
	return true;
}