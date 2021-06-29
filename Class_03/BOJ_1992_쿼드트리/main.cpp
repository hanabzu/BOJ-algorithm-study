/* hanabzu */
/* BOJ_1992 쿼드트리 */

#include <iostream>
using namespace std;

int N;
string* video;

string quadtree(int n, int row, int col);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	video = new string[N];
	for (int i = 0; i < N; i++) {
		cin >> video[i];
	}

	cout << quadtree(N, 0, 0);
}

string quadtree(int n, int row, int col) {
	string str = "";
	bool flag;
	int half = n >> 1;
	char dot[4] = { video[row][col],		video[row][col + half],
					video[row + half][col], video[row + half][col + half], };
	int pos[4][2] = { {0,0},{0,half},{half,0},{half,half} };

	for (int i = 0; i < 4; i++) {
		flag = 0;
		for (int r = 0; r < half; r++) {
			for (int c = 0; c < half; c++) {
				if (dot[i] != video[row + pos[i][0] + r][col + pos[i][1] + c]) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1) {
			str += quadtree(n >> 1, row + pos[i][0], col + pos[i][1]);
		}
		else {
			str += dot[i];
		}
	}
	if (str == "1111") {
		return "1";
	}
	else if (str == "0000") {
		return "0";
	}
	return "(" + str + ")";
}
