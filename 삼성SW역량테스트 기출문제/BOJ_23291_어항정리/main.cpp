/* BOJ_23291 어항 정리 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXN = 100;

int N, K, page = 0, ans = 0, p = 1, w = 1, h = 1;
int A[MAXN], table[2][MAXN][MAXN], tmp[MAXN][MAXN];

void roll();
void stack();
void spin();
void regulate();
void stretch();

bool isEnd();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	while (!isEnd()) {
		ans++;
		int minn = *min_element(A, A + N);
		for (int i = 0; i < N; i++) {
			if (A[i] == minn) A[i]++;
		}

		roll();
		regulate();
		stretch();
		stack();
		regulate();
		stretch();
	}

	cout << ans;
	return 0;
}

void roll() {
	table[page][0][0] = A[0];
	p = 1, w = 1, h = 1;
	while (h <= N - p) {
		spin();
		swap(w, h);

		for (int i = 0; i < w; i++) {
			table[page][h][i] = A[p++];
		}
		h++;
	}

	while (p < N) {
		table[page][h - 1][w++] = A[p++];
	}
}

void stack() {
	w = (N >> 2);
	h = 4;

	for (int i = 0; i < w; i++) {
		table[page][0][i] = A[3 * w - 1 - i];
		table[page][1][i] = A[w + i];
		table[page][2][i] = A[w - 1 - i];
		table[page][3][i] = A[3 * w + i];
	}
}

void regulate() {
	int new_page = page ^ 1;
	int diff;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if(table[page][i][j] != 0 && table[page][i + 1][j] != 0) {
				diff = table[page][i][j] - table[page][i + 1][j];
				if (diff > 0) {
					diff /= 5;
					table[new_page][i][j] -= diff;
					table[new_page][i + 1][j] += diff;
				}
				else if (diff < 0) {
					diff = (-diff) / 5;
					table[new_page][i][j] += diff;
					table[new_page][i + 1][j] -= diff;
				}
			}
			if (table[page][i][j] != 0 && table[page][i][j + 1] != 0) {
				diff = table[page][i][j] - table[page][i][j + 1];
				if (diff > 0) {
					diff /= 5;
					table[new_page][i][j] -= diff;
					table[new_page][i][j + 1] += diff;
				}
				else if (diff < 0) {
					diff = (-diff) / 5;
					table[new_page][i][j] += diff;
					table[new_page][i][j + 1] -= diff;
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			table[new_page][i][j] += table[page][i][j];
		}
	}
	memset(table[page], 0, sizeof table[page]);
	page = new_page;
}

void stretch() {
	p = 0;
	for (int i = 0; i < w; i++) {
		for (int j = h - 1; j >= 0; j--) {
			if (table[page][j][i] == 0) continue;

			A[p++] = table[page][j][i];
		}
	}
	memset(table[page], 0, sizeof table[page]);
}

void spin() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < h; j++) {
			tmp[i][j] = table[page][i][j];
			table[page][i][j] = 0;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < h; j++) {
			table[page][i][j] = tmp[h - 1 - j][i];
		}
	}
}

bool isEnd() {
	int maxn = *max_element(A, A + N);
	int minn = *min_element(A, A + N);

	return (maxn - minn) <= K;
}