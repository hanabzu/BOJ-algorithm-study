/* BOJ_2725 보이는 점의 개수 */
/* hanabzu */

#include <iostream>
#define MAXN 1001
using namespace std;

int C, N;
bool isObscured[MAXN][MAXN];
int n[MAXN + 1];

int getVisible(int u);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	isObscured[0][0] = true;
	for (int r = 1; r <= MAXN; r++) {
		for (int c = 1; c <= MAXN; c++) {
			if (!isObscured[r][c]) {
				int mr = r;
				int mc = c;
				while (1) {
					mr += r;
					mc += c;
					if ((mr < MAXN) && (mc < MAXN)) {
						isObscured[mr][mc] = true;
					}
					else if ((mr >= MAXN) && (mc >= MAXN)) {
						break;
					}
				}
			}
		}
	}

	n[1] = 3;
	cin >> C;
	while (C--) {
		cin >> N;
		cout << getVisible(N) << '\n';
	}

	return 0;
}

int getVisible(int u) {
	if (n[u] != 0) return n[u];

	for (int i = 1; i <= u; i++) {
		if (!isObscured[i][u]) n[u]++;
		if (!isObscured[u][i]) n[u]++;
	}
	n[u] += getVisible(u - 1);
	return n[u];
}