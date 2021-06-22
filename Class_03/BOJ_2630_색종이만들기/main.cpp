/* hanabzu */
/* BOJ_2630 색종이 만들기 */

#include <iostream>
using namespace std;

int n, color_num[2] = { 0,0 };
bool mat[128][128];

void cut(int row, int col, int size);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	cut(0, 0, n);

	cout << color_num[0] << '\n' << color_num[1];

	return 0;
}

void cut(int row, int col, int size) {
	bool color = mat[row][col];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (mat[row + i][col + j] != color) {
				cut(row, col, size >> 1);
				cut(row + (size >> 1), col, size >> 1);
				cut(row, col + (size >> 1), size >> 1);
				cut(row + (size >> 1), col + (size >> 1), size >> 1);
				return;
			}
		}
	}
	color_num[color]++;
}