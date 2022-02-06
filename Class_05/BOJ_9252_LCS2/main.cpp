/* BOJ_9251 LCS */
/* hanabzu */

#include <iostream>
using namespace std;

const int MAXS = 1000;
string X, Y, LCS = "";
int m, n;
int c[MAXS + 1][MAXS + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> X >> Y;
	m = X.length();
	n = Y.length();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (X[i] == Y[j]) {
				c[i + 1][j + 1] = c[i][j] + 1;
			}
			else if (c[i][j + 1] >= c[i + 1][j]) {
				c[i + 1][j + 1] = c[i][j + 1];
			}
			else {
				c[i + 1][j + 1] = c[i + 1][j];
			}
		}
	}

	cout << c[m][n] << '\n';

	if (c[m][n] > 0) {
		while (1) {
			if (m == 0 || n == 0) break;
			if (X[m - 1] == Y[n - 1]) {
				LCS = X[m - 1] + LCS;
				m--;
				n--;
			}
			else {
				if (c[m][n] == c[m - 1][n]) {
					m--;
				}
				else if (c[m][n] == c[m][n - 1]) {
					n--;
				}
			}
		}
	}
	cout << LCS;
	return 0;
}